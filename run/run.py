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



def world_to_pixel(world_coords, origin, resolution, map_image):
    x, y = world_coords
    pixel_x = int((x - origin[0]) / resolution)
    pixel_y = map_image.shape[0] - int((y - origin[1]) / resolution) # the Coordinate system of cv2 located in the left top
    return pixel_x, pixel_y

def pixel_to_world(pixel_coords, origin, resolution, map_image):
    px, py = pixel_coords
    world_x = px * resolution + origin[0]
    world_y = (map_image.shape[0] - py)* resolution + origin[1]
    return world_x, world_y

def find_nearest_feasible_point(map_image, pixel_coords, result):
    h, w = map_image.shape
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

def is_point_feasible(world_coords, map_image, window_size, result, origin, resolution):
    # convert to pixel coordinate
    pixel_coords = world_to_pixel(world_coords, origin, resolution, map_image)
    px, py = pixel_coords
    print(px, py)

    if 0 <= px < map_image.shape[1] and 0 <= py < map_image.shape[0]:
        # if map_image[py, px] > 220:
        if np.all(map_image[py-window_size:py+window_size, px-window_size:px+window_size] > 220):
            return True, world_coords
        else:
            # find the nearest feasible pixel
            nearest_pixel = find_nearest_feasible_point(map_image, (py, px), result)
            nearest_world = pixel_to_world(nearest_pixel, origin, resolution, map_image)
            return False, nearest_world
    else:
        raise ValueError("输入点超出地图范围！")


def get_pose(query_text, client, system_prompt,  map_image, window_size, result, origin, resolution):
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
        response = client.chat.completions.create(
            model="gpt-4-turbo-2024-04-09",
            messages=[
            {"role": "system", "content": system_prompt},
            {"role": "user", "content": query_text},
            ],
            stream=False
        )

        result_from_gpt = response.choices[0].message.content.strip('`').strip()
        result_from_gpt = json.loads(result_from_gpt)
        print('location:',result_from_gpt)

        if not isinstance(result_from_gpt,list):
            return None, None, None
        if len(result_from_gpt) == 0:
            return None, None, None
        x,y,_ = result_from_gpt[0]["中心坐标"]
        input_coords = [x, y]
        feasible, result_coords = is_point_feasible(input_coords, map_image, window_size, result, origin, resolution)
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

def execute_navigation_command(x, y, theta):
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
        print(result.stderr)
        # if "Result: 步进完成." in result.stderr:
        if result.returncode == 0:
            print("Navigation command succeeded.")
            return True
        else:
            print(f"Unexpected response: {result.stdout}")
            return False
    except subprocess.CalledProcessError as e:
        print(f"Error executing navigation command: {e.stderr}")
        return False


def main():
    # r = sr.Recognizer()

    ros2_process = subprocess.Popen(
    ["ros2", "run", "woosh_robot_agent", "agent",
     "--ros-args", "-r", "__ns:=/woosh_robot", "-p", 'ip:="169.254.128.2"'],
    stdout=subprocess.PIPE,
    stderr=subprocess.PIPE,
    text=True
)
    time.sleep(2)


    image_path = 'map_mid360_editted.png'
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
    with open('system_prompt.txt') as f:
        system_prompt = f.read()
    GPT_KEY = os.environ.get('GPT_KEY', "sk-85sYGSCUBoQHvGQp72E4Ed5e5c844133Ba143dBf54Cc7c80")
    GPT_BASE = os.environ.get('GPT_BASE', "https://m.gptapi.us/v1")
    client = OpenAI(api_key = GPT_KEY,
                    base_url = GPT_BASE)
    while True:
        # _ = input('Press any key to continue:')

        # with sr.Microphone() as source:
        #     print("请说出指令：")
        #     audio = r.listen(source)
        # try:
        #     print("语音识别结果:")
        #     query_text = r.recognize_google(audio, language='zh-cn')
        #     query_text = query_text.strip()
        #     print(query_text)
        # except sr.UnknownValueError:
        #     print("语音识别失败")
        # except sr.RequestError as e:
        #     print(f"语音服务连接失败 : {e}")
        query_text = "大门旁边右侧的绿植"
        print(f"Processing query: {query_text}")
        x, y, theta = get_pose(query_text,client,system_prompt, map_image, window_size, result, origin, resolution)
        if x is not None and y is not None and theta is not None:
            success = execute_navigation_command(x, y, theta)
            if success != 1:
                print("Exiting loop due to failure in navigation command.")
                break
        else:
            print("Skipping navigation due to invalid pose data.")
        break

if __name__ == "__main__":
    main()
