import requests
import json
import subprocess
import time
import numpy as np
import cv2
from scipy.spatial import cKDTree
import speech_recognition as sr
import math
import datetime
import json
import logging
import re,os
from flask import Flask, request, jsonify
from Node import NodeManager

app = Flask(__name__)


def prepare4log():
    os.makedirs('./log',exist_ok=True)
    log_filename = datetime.datetime.now().strftime("log/log_%Y-%m-%d_%H-%M-%S.log")
    logging.basicConfig(filename=log_filename, level=logging.INFO, format="%(asctime)s - %(message)s")

def prepare_map(image_path = 'scan_by_robot.png'):
    global resolution, origin, map_image, system_prompt, window_size, result
    map_image = cv2.imread(image_path, cv2.IMREAD_GRAYSCALE)
    # extract all the pixel representing the feasible area
    window_size = 10
    result = []
    for i in range(map_image.shape[0]):
        for j in range(map_image.shape[1]):
            # bbox
            top = max(0, i - window_size)
            bottom = min(map_image.shape[0], i + window_size)
            left = max(0, j - window_size)
            right = min(map_image.shape[1], j + window_size)
            
            window = map_image[top:bottom, left:right]
            
            if np.all(window > 220):
                result.append((i, j))
    # YAML 文件参数
    resolution = 0.03  # each pixel -> real distance
    origin = [-14.25103271484375, -7.429531860351562, 0]
    with open('system_prompt_0625.txt') as f:
        system_prompt = f.read()

def world_to_pixel(world_coords):
    x, y = world_coords
    pixel_x = int((x - origin[0]) / resolution)
    pixel_y = map_image.shape[0] - int((y - origin[1]) / resolution) # the Coordinate system of cv2 located in the left top
    return pixel_x, pixel_y

def pixel_to_world(pixel_coords):
    px, py = pixel_coords
    world_x = px * resolution + origin[0]
    world_y = (map_image.shape[0] - py)* resolution + origin[1]
    return world_x, world_y

def find_nearest_feasible_point(pixel_coords):
    # free_points = np.argwhere(map_image > 220)  # get all the feasible area
    free_points = result
    tree = cKDTree(free_points)
    distance, index = tree.query(pixel_coords, k = 1,distance_upper_bound=400)  # find the nearest feasible point
    nearest_pixel = free_points[index]
    return (nearest_pixel[1], nearest_pixel[0])

def theta2Quaternion(x,y,theta):
    z = math.sin(theta / 2)
    w = math.cos(theta / 2)
    return x, y, z, w 

def calculate_theta(x1, y1, x2, y2): #x2 -> x1
    dx = x1 - x2  #
    dy = y1 - y2  
    theta = math.atan2(dy, dx)  # calculate angle
    return theta

def is_point_feasible(world_coords):
    # convert to pixel coordinate
    pixel_coords = world_to_pixel(world_coords)
    px, py = pixel_coords

    if 0 <= px < map_image.shape[1] and 0 <= py < map_image.shape[0]:
        # if map_image[py, px] > 220:
        if np.all(map_image[py-window_size:py+window_size, px-window_size:px+window_size] > 220):
            return True, world_coords
        else:
            # find the nearest feasible pixel
            nearest_pixel = find_nearest_feasible_point((py, px))
            nearest_world = pixel_to_world(nearest_pixel)
            return False, nearest_world
    else:
        logging.error("输入点超出地图范围！")
        raise ValueError("输入点超出地图范围！")

def get_pose(query_text):
    try:
        result_from_gpt = requests.post("http://172.18.35.200:8000/uploads/llm_queries", json={"instruction": system_prompt, "prompt": query_text} )
        result_from_gpt = result_from_gpt.json()['read_message']
        result_from_gpt = result_from_gpt.replace('```json\n','')
        result_from_gpt = result_from_gpt.replace('```','')
        result_from_gpt = json.loads(result_from_gpt)
        logging.info(f'location: {result_from_gpt}')

        if not isinstance(result_from_gpt,list):
            return None, None, None
        if len(result_from_gpt) == 0:
            return None, None, None
        x,y,theta = result_from_gpt[0]["中心坐标"]
        input_coords = [x, y]
        feasible, result_coords = is_point_feasible(input_coords)
        if feasible:
            logging.info(f"输入点 {input_coords} 在可行区域内。")
        else:
            new_x, new_y = result_coords
            theta = calculate_theta(x, y, new_x, new_y) #new 指向 old
            logging.info(f"输入点 {input_coords} 不在可行区域，最近的可行点是 {new_x, new_y}.")
            x, y = new_x, new_y
        return x, y, theta
    except requests.RequestException as e:
        logging.error(f"Error during request: {e}")
        return None, None, None
    except json.JSONDecodeError as e:
        logging.error(f"Error decoding JSON response: {e}")
        return None, None, None


@app.route('/get_pose_speed', methods=['POST'])
def get_pose_speed_handler():
    [x,y,theta],[linear,angular] = node.get_pose_speed()
    return jsonify({"pose":[x,y,theta],"speed": [linear,angular]})

@app.route('/stop', methods=['POST'])
def action_stop_handler():
    success_flag,info,state = node.stop()
    return jsonify({"success_flag":success_flag,"message": info,"state":state})

@app.route('/text_nav', methods=['POST'])
def text_nav_handler():
    data = request.get_json()
    goal_text = data.get('query_text')

    if not goal_text:
        return jsonify({"message": "Goal text is required"}), 400
    
    x, y, theta = get_pose(goal_text)
    if x is None or y is None or theta is None:
        logging.warning("Skipping navigation due to invalid pose data.")
        return False, "Skipping navigation due to invalid pose data.", -2

    success_flag,info,state = node.navigation(x, y, theta)

    return jsonify({"success_flag":success_flag,"message": info,"state":state})


@app.route('/forward', methods=['POST'])
def forward_handler():
    data = request.get_json()
    direction = str(data.get('direction'))
    distance = float(data.get('distance'))

    if not distance:
        return jsonify({"message": "Distance is required"}), 400

    if direction == 'backward' or direction == 'right':
        distance = -1*distance
    if direction == 'forward' or direction == 'backward':
        success_flag,info,state = node.forward(distance)
    if direction == 'left' or direction == 'right':
        pass
        success_flag,info,state = node.shift(distance)

    return jsonify({"success_flag":success_flag,"message": info,"state":state})

@app.route('/rotate', methods=['POST'])
def rotate_handler():
    data = request.get_json()
    direction = str(data.get('direction'))
    theta = float(data.get('theta'))
    if direction == 'right':
        theta =  -1*theta

    if not theta:
        return jsonify({"message": "Theta is required"}), 400

    success_flag,info,state = node.rotate(theta)

    return jsonify({"success_flag":success_flag,"message": info,"state":state})


@app.route('/get_lidar', methods=['POST'])
def lidar_handler():
    lidar_scan, _ = node.get_lidar()
    angles = np.linspace(-2.1999948024749756, 2.1999948024749756, len(lidar_scan))  # 角度范围
    indice = np.where( (angles >= -math.pi/4) & (angles <= math.pi/4))
    lidar_scan = lidar_scan[indice].tolist()
    return jsonify({"lidar_scan":lidar_scan})

def prepare_node():
    global node
    node = NodeManager()


if __name__ == "__main__":
    prepare4log()
    prepare_map()

    woosh_agent_log = datetime.datetime.now().strftime("log/woosh_agent_log_%Y-%m-%d_%H-%M-%S.log")
    f = open(woosh_agent_log, 'w')
    ros2_process = subprocess.Popen(
    ["ros2", "run", "woosh_robot_agent", "agent",
     "--ros-args", "-r", "__ns:=/woosh_robot", "-p", 'ip:="169.254.128.2"'],
    # ["ros2", "run", "woosh_robot_agent", "agent",
    #  "--ros-args", "-r", "__ns:=/woosh_robot", "-p", 'ip:="10.27.134.6"'],
    stdout=f,
    stderr=subprocess.STDOUT,
    text=True
)
    time.sleep(3)
    prepare_node()
    app.run(host='0.0.0.0',debug=True,threaded=True)
