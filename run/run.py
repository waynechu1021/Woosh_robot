import subprocess
import time
import numpy as np
import cv2
import math
import datetime
import logging
import os
from map_utils import convert_text2cordinate, convert_image2pose
from icp import convert_lidar_scan_to_pcd, localization_refine
from flask import Flask, request, jsonify
from Node import NodeManager
import open3d as o3d
import yaml


app = Flask(__name__)


def prepare4log():
    os.makedirs('./log',exist_ok=True)
    log_filename = datetime.datetime.now().strftime("log/log_%Y-%m-%d_%H-%M-%S.log")
    logging.basicConfig(filename=log_filename, level=logging.INFO, format="%(asctime)s - %(message)s")

def prepare_map(file_path = './map/scan_by_robot'):
    image_path = file_path + '.png'
    yaml_path = file_path + '.yaml'
    sp_path = file_path + '.txt'
    global resolution, origin, map_image, system_prompt, window_size, free_points
    map_image = cv2.imread(image_path, cv2.IMREAD_GRAYSCALE)
    # extract all the pixel representing the feasible area
    window_size = 10
    free_points = []
    for i in range(map_image.shape[0]):
        for j in range(map_image.shape[1]):
            # bbox
            top = max(0, i - window_size)
            bottom = min(map_image.shape[0], i + window_size)
            left = max(0, j - window_size)
            right = min(map_image.shape[1], j + window_size)
            
            window = map_image[top:bottom, left:right]
            
            if np.all(window > 220):
                free_points.append((i, j))
    # YAML file
    with open(yaml_path, "r", encoding="utf-8") as f:
        data = yaml.safe_load(f)
        resolution = data['resolution']  # each pixel -> real distance
        origin = data['origin']
    with open(sp_path) as f:
        system_prompt = f.read()

def prepare_icp():
    global map_pcd
    edges = cv2.Canny(map_image, 50, 150)  # Canny 边缘检测
    # Find the coordinates of the edge points
    y_idxs, x_idxs = np.where(edges > 0) # in opencv axis
    edge_points = np.column_stack((x_idxs, y_idxs)).astype(np.float32)
    edge_points = np.concatenate([edge_points,np.zeros((edge_points.shape[0],1))],axis=1)
    # 转换为 Open3D 点云格式
    map_pcd = o3d.geometry.PointCloud()
    map_pcd.points = o3d.utility.Vector3dVector(edge_points)


def localization(initialize = False):
    x, y, theta = convert_image2pose()
    logging.info(f"Got vpr localization = {x, y, theta}")
    if initialize:
        success_flag,info,state = node.init_robot(x, y ,theta)
        logging.info(f"Global lnitialize localization!")
    else:
        success_flag,info,state = node.set_pose(x, y, theta)
        logging.info(f"Global localization after navigation!")
    # lidar_scan, _ = node.get_lidar()
    # angles = np.linspace(-2.1999948024749756, 2.1999948024749756, len(lidar_scan))
    # indice = np.where( (angles >= -math.pi/4) & (angles <= math.pi/4))
    # lidar_scan = lidar_scan[indice]
    # lidar_pcd = convert_lidar_scan_to_pcd(lidar_scan, [x, y, theta], map_image, origin, resolution)
    # x, y, theta = localization_refine(map_pcd, lidar_pcd, [x, y, theta], map_image, origin, resolution)
    # if initialize:
    #     success_flag,info,state = node.init_robot(x, y ,theta)
    #     logging.info(f"Local icp lnitialize localization!")
    # else:
    #     success_flag,info,state = node.set_pose(x, y, theta)
    #     logging.info(f"Local icp localization after navigation!")
    return success_flag,info,state

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
    
    x, y, theta = convert_text2cordinate(goal_text, system_prompt, map_image, origin, resolution, window_size, free_points)
    if x is None or y is None or theta is None:
        logging.warning("Skipping navigation due to invalid pose data.")
        return False, "Skipping navigation due to invalid pose data.", -2

    success_flag,info,state = node.navigation(x, y, theta)
    [x,y,theta],_ = node.get_pose_speed()
    logging.info(f"current pose = [{x, y, theta}]")
    # localization()

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
    angles = np.linspace(-2.1999948024749756, 2.1999948024749756, len(lidar_scan))
    indice = np.where( (angles >= -math.pi/4) & (angles <= math.pi/4))
    lidar_scan = lidar_scan[indice].tolist()
    return jsonify({"lidar_scan":lidar_scan})


@app.route('/init_robot', methods=['POST'])
def init_robot_handler():
    data = request.get_json(silent=True)
    if not data:
        success_flag, info, state = node.init_robot()
    else:
        x = float(data.get('x'))
        y = float(data.get('y'))
        theta = float(data.get('theta'))
        if not x or not y or not theta:
            success_flag,info,state = node.init_robot()
        else:
            success_flag,info,state = node.init_robot(x, y ,theta)
    return jsonify({"success_flag":success_flag,"message": info,"state":state})

@app.route('/mute', methods=['POST'])
def mute_handler():
    data = request.get_json(silent=True)
    if not data:
        success_flag, info, state = node.mute()
    else:
        mute = bool(data.get('mute'))
        if mute is None:
            success_flag,info,state = node.mute()
        else:
            success_flag,info,state = node.mute(mute)
    return jsonify({"success_flag":success_flag,"message": info,"state":state})


@app.route('/set_pose', methods=['POST'])
def set_pose_handler():
    data = request.get_json()
    x = float(data.get('x'))
    y = float(data.get('y'))
    theta = float(data.get('theta'))
    if not x or not y or not theta:
        return jsonify({"message": "x, y and theta are required"}), 400
    success_flag,info,state = node.set_pose(x, y ,theta)
    return jsonify({"success_flag":success_flag,"message": info,"state":state})

def prepare_node():
    global node
    node = NodeManager()


if __name__ == "__main__":
    prepare4log()
    prepare_map()
    prepare_icp()

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
    node.mute()
    # localization(initialize=True)
    node.init_robot()
    app.run(host='0.0.0.0',debug=False,threaded=True)
