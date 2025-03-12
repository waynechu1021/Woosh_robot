import requests
import json
import subprocess
import time
import numpy as np
import cv2
from scipy.spatial import cKDTree
import speech_recognition as sr
import math
from openai import OpenAI
import json
import os
import re
from flask import Flask, request, jsonify

app = Flask(__name__)

image_path = 'workspace/Woosh_robot/run/map_mid360_editted_03_04.png'
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
resolution = 0.05  # each pixel -> real distance
# origin = [-6.884753227233887, -23.146076202392578, 0.0]  # the point of left down
origin = [-29.641035598313977, -11.984327112417178, 0]
with open('workspace/Woosh_robot/run/system_prompt.txt') as f:
    system_prompt = f.read()
# GPT_KEY = os.environ.get('GPT_KEY', "")
# GPT_BASE = os.environ.get('GPT_BASE', "https://m.gptapi.us/v1")
# client = OpenAI(api_key = GPT_KEY,
#                 base_url = GPT_BASE)


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

def calculate_theta(x1, y1, x2, y2): #x2指向x1
    dx = x1 - x2  # 
    dy = y1 - y2  #
    theta = math.atan2(dy, dx)  # 计算角度
    return theta

def is_point_feasible(world_coords):
    # convert to pixel coordinate
    pixel_coords = world_to_pixel(world_coords)
    px, py = pixel_coords
    print(px, py)

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
        raise ValueError("输入点超出地图范围！")

def get_lidar():
    scan_command = [
        "ros2", "service", "call", "/woosh_robot/robot/ScannerData",
        "woosh_robot_msgs/srv/ScannerData",
    ]
    print(f"Executing lidar request command: {' '.join(scan_command)}")
    try:
        result = subprocess.run(
            scan_command, capture_output=True, text=True, check=True
        )
        print(result.stderr)
        if result.returncode == 0:
            print("Lidar request command succeeded.")

            pattern = r"pose=woosh_common_msgs.msg.Pose2D\((.*)\), commu"
            match = re.findall(pattern, result.stdout)
            pos = match[1] # 获取匹配的数字部分
            initial_position = [float(re.findall('x=(.*), y',pos)[0]),float(re.findall('y=(.*), t',pos)[0]),float(re.findall('theta=(.*)',pos)[0])]

            pattern = r"ranges=\[(.*)\]"
            match = re.findall(pattern, result.stdout)

            if match:
                ranges_str = match[1] # 获取匹配的数字部分
                ranges_list = [float(num) for num in ranges_str.split(',') if num.strip()]
                ranges_list = np.array(ranges_list)
                return ranges_list, initial_position
            else:
                print("No match found.")
                return None, None
        else:
            print(f"Unexpected response: {result.stdout}")
            return None, None
    except subprocess.CalledProcessError as e:
        print(f"Error executing lidar request command: {e.stderr}")
        return None, None

def get_pose(query_text):
    try:
        '''
        HOVSG
        '''
        # headers = {"Content-Type": "application/json"}
        # payload = {"query": query_text}

        # response = requests.post(QUERY_URL, headers=headers, data=json.dumps(payload))
        # response.raise_for_status()

        # data = response.json()
        # x = data.get("center", [None, None, None])[0]
        # y = data.get("center", [None, None, None])[1]
        # theta = data.get("center", [None, None, None])[2]

        # if x is None or y is None or theta is None:
        #     print(f"Invalid pose data in response: {data}")
        #     return None, None, None
        '''
        gpt
        '''
        # response = client.chat.completions.create(
        #     model="gpt-4-turbo-2024-04-09",
        #     messages=[
        #     {"role": "system", "content": system_prompt},
        #     {"role": "user", "content": query_text},
        #     ],
        #     stream=False
        # )
        # result_from_gpt = response.choices[0].message.content.strip('`').strip()

        result_from_gpt = requests.post("http://172.18.35.200:8000/uploads/llm_queries", json={"instruction": system_prompt, "prompt": query_text} )
        result_from_gpt = result_from_gpt.json()['read_message']

        result_from_gpt = json.loads(result_from_gpt)
        print('location:',result_from_gpt)

        if not isinstance(result_from_gpt,list):
            return None, None, None
        if len(result_from_gpt) == 0:
            return None, None, None
        x,y,_ = result_from_gpt[0]["中心坐标"]
        input_coords = [x, y]
        feasible, result_coords = is_point_feasible(input_coords)
        if feasible:
            print(f"输入点 {input_coords} 在可行区域内。")
        else:
            new_x, new_y = result_coords
            theta = calculate_theta(x, y, new_x, new_y) #new 指向 old
            print(f"输入点 {input_coords} 不在可行区域，最近的可行点是 {new_x, new_y}.")
            x, y = new_x, new_y
        return x, y, theta
    except requests.RequestException as e:
        print(f"Error during request: {e}")
        return None, None, None
    except json.JSONDecodeError as e:
        print(f"Error decoding JSON response: {e}")
        return None, None, None

def excute_forward_command(distance):
    if distance > 0:
        lidar_scan, _ = get_lidar()
        angles = np.linspace(-2.1999948024749756, 2.1999948024749756, len(lidar_scan))  # 角度范围
        indice = np.where( (angles >= -math.pi/6) & (angles <= math.pi/6) )
        lidar_scan = lidar_scan[indice]
        max_distance = np.min(lidar_scan) * 0.95
        if max_distance < distance:
            distance = max_distance 
            print(f'It can only proceed with {max_distance} meters')
    forward_command = [
    "ros2", "action", "send_goal", "/woosh_robot/ros/StepControl", 
    "woosh_ros_msgs/action/StepControl", 
    f"{{arg:{{action:{{value: 1}}, avoid: 1, steps:[{{mode:{{value: 1}}, speed: 0.5, value: {distance}}}]}}}}",
    "--feedback"]
    print(f"Executing navigation command: {' '.join(forward_command)}")
    try:
        result = subprocess.run(
            forward_command, capture_output=True, text=True, check=True
        )
        return_code = re.findall(r"ret:\n  action: woosh.ros.action.StepControl\n  state:\n    value: (.*)\n", result.stdout)
        if len(return_code) == 1 and int(return_code[0]) == 1:
            msg = "Forward command succeeded."
            print(msg)
            return True, msg, int(return_code[0])
        elif int(return_code[0]) == -1 or int(return_code[0]) == 5:
            msg = "Forward command failed."
            print(msg)
            return False, msg, int(return_code[0])
        elif int(return_code[0]) == 2:
            msg = "Forward command still processing"
            print(msg)
            return False, msg, int(return_code[0])
        else:
            msg = f"Unexpected response: {result.stdout}"
            print(msg)
            return False, msg, int(return_code[0])
    except subprocess.CalledProcessError as e:
        msg = f"Error executing forward command: {e.stderr}"
        print(msg)
        return False, msg, -1

def execute_navigation_command(query_text):
    print(f"Processing query: {query_text}")
    x, y, theta = get_pose(query_text)
    if x is None or y is None or theta is None:
        print("Skipping navigation due to invalid pose data.")
        return False, "Skipping navigation due to invalid pose data.",-2
    # x, y = 0.55, -0.65
    # nav_command = [
    #     "ros2", "run", "woosh_robot_demo", "movebase_goal",
    #     "--ros-args", "-p", f"t_x:={x}", "-p", f"t_y:={y}", "-p", f"t_theta:={theta}"
    # ]
    nav_command = [
    "ros2", "action", "send_goal", "/woosh_robot/ros/MoveBase", 
    "woosh_ros_msgs/action/MoveBase", 
    f"{{arg:{{poses:[{{x: {x}, y: {y}, theta: {theta}}}], target_pose:{{x: {x}, y: {y}, theta: {theta}}}, execution_mode:{{value: 1}}, action:{{value: 1}}}}}}",
    "--feedback"
]
    print(f"Executing navigation command: {' '.join(nav_command)}")
    try:
        result = subprocess.run(
            nav_command, capture_output=True, text=True, check=True
        )
        # print(result.stderr)
        # if "Result: 步进完成." in result.stderr:
        return_code = re.findall(r"ret:\n  action: woosh.ros.action.MoveBase\n  state:\n    value: (.*)\n", result.stdout)
        # if result.returncode == 0:
        if len(return_code) == 1 and int(return_code[0]) == 1:
            msg = "Navigation command succeeded."
            print(msg)
            return True, msg, int(return_code[0])
        elif int(return_code[0]) == -1 or int(return_code[0]) == 5:
            msg = "Navigation command failed."
            print(msg)
            return False, msg, int(return_code[0])
        elif int(return_code[0]) == 2:
            msg = "Navigation command still processing"
            print(msg)
            return False, msg, int(return_code[0])
        else:
            msg = f"Unexpected response: {result.stdout}"
            print(msg)
            return False, msg, int(return_code[0])
    except subprocess.CalledProcessError as e:
        msg = f"Error executing navigation command: {e.stderr}"
        print(msg)
        return False, msg, -1



@app.route('/text_nav', methods=['POST'])
def text_nav_handler():
    data = request.get_json()
    goal_text = data.get('query_text')

    if not goal_text:
        return jsonify({"message": "Goal text is required"}), 400

    success_flag,info,state = execute_navigation_command(goal_text)

    return jsonify({"success_flag":success_flag,"message": info,"state":state})


@app.route('/forward', methods=['POST'])
def forward_handler():
    data = request.get_json()
    distance = float(data.get('distance'))

    if not distance:
        return jsonify({"message": "Distance is required"}), 400

    success_flag,info,state = excute_forward_command(distance)

    return jsonify({"success_flag":success_flag,"message": info,"state":state})

if __name__ == "__main__":
    ros2_process = subprocess.Popen(
    ["ros2", "run", "woosh_robot_agent", "agent",
     "--ros-args", "-r", "__ns:=/woosh_robot", "-p", 'ip:="169.254.128.2"'],
    stdout=subprocess.PIPE,
    stderr=subprocess.PIPE,
    text=True
)
    time.sleep(2)
    app.run(host='0.0.0.0',debug=True)
