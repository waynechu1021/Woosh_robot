import requests
import json
import subprocess
import time
import numpy as np
import cv2
from scipy.spatial import cKDTree
import math

# 配置变量
QUERY_URL = "http://10.16.2.104:12345/hovsg_query"
QUERY_TEXTS = ["find the elevator", "find the stairs", "find the exit"]  # 可修改为动态输入或其他来源
INTERVAL = 5  # 每次循环的间隔时间（秒）

# 加载地图和参数
image_path = '/home/wayne/workspace/run/map.png'  # 地图文件路径
map_image = cv2.imread(image_path, cv2.IMREAD_GRAYSCALE)

# YAML 文件参数
resolution = 0.05  # 每像素对应的实际距离（单位：米）
origin = [-6.884753227233887, -23.146076202392578, 0.0]  # 左下角原点的实际坐标

def world_to_pixel(world_coords):
    """
    将世界坐标转换为图像像素坐标。
    """
    x, y = world_coords
    pixel_x = int((x - origin[0]) / resolution)
    pixel_y = map_image.shape[0] - int((y - origin[1]) / resolution)
    return pixel_x, pixel_y

def pixel_to_world(pixel_coords):
    """
    将图像像素坐标转换为世界坐标。
    """
    px, py = pixel_coords
    world_x = px * resolution + origin[0]
    world_y = (map_image.shape[0] - py)* resolution + origin[1]
    return world_x, world_y

def find_nearest_feasible_point(map_image, pixel_coords):
    """
    找到最近的可行点。
    """
    h, w = map_image.shape
    free_points = np.argwhere(map_image > 200)  # 获取所有白色区域（可行区域）
    tree = cKDTree(free_points)  # 构建空间索引
    distance, index = tree.query(pixel_coords)  # 查询最近点
    nearest_pixel = free_points[index]
    return (nearest_pixel[1], nearest_pixel[0])

def is_point_feasible(world_coords):
    """
    检查输入点是否在可行区域。
    如果不可行，返回最近的可行点。
    """
    # 转换为像素坐标
    pixel_coords = world_to_pixel(world_coords)
    px, py = pixel_coords
    print(px, py)

    # 检查是否在图像范围内
    if 0 <= px < map_image.shape[1] and 0 <= py < map_image.shape[0]:
        if map_image[py, px] > 200:  # 检查是否为白色区域
            return True, world_coords
        else:
            # 找最近的可行点
            nearest_pixel = find_nearest_feasible_point(map_image, (py, px))
            nearest_world = pixel_to_world(nearest_pixel)
            return False, nearest_world
    else:
        raise ValueError("输入点超出地图范围！")


def get_pose(query_text):
    """
    向服务器发送查询请求并提取位置信息
    """
    try:
        # 根据具体的 curl 指令设置请求参数
        headers = {"Content-Type": "application/json"}
        payload = {"query": query_text}

        # 发送 POST 请求
        response = requests.post(QUERY_URL, headers=headers, data=json.dumps(payload))
        response.raise_for_status()  # 检查响应状态码

        # 解析响应内容
        data = response.json()
        x = data.get("center", [None, None, None])[0]
        y = data.get("center", [None, None, None])[1]
        theta = data.get("center", [None, None, None])[2]

        if x is None or y is None or theta is None:
            print(f"Invalid pose data in response: {data}")
            return None, None, None
        input_coords = [x, y]
        feasible, result_coords = is_point_feasible(input_coords)
        if feasible:
            print(f"输入点 {input_coords} 在可行区域内。")
        else:
            # k = (result_coords[1] - y)/(result_coords[0] - x + 10e-6)
            # new_x = result_coords[0] + 0.7 /math.sqrt(k*k + 1)
            # new_y = result_coords[1] + 0.7 /math.sqrt(k*k + 1)*k
            new_x, new_y = result_coords
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
    """
    构造并执行 ROS 2 导航命令
    """
    x, y = 8.8, -15.4
    nav_command = [
        "ros2", "run", "woosh_robot_demo", "movebase_goal",
        "--ros-args", "-p", f"t_x:={x}", "-p", f"t_y:={y}", "-p", f"t_theta:={theta}"
    ]
    print(f"Executing navigation command: {' '.join(nav_command)}")
    try:
        result = subprocess.run(
            nav_command, capture_output=True, text=True, check=True
        )
        print(result.stderr)
        # 检查输出是否包含 success
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
    """
    主循环：获取查询文本，发送请求，执行导航命令
    """
    while True:
        query_text = input('Please input the query text: ')
        print(f"Processing query: {query_text}")
        x, y, theta = get_pose(query_text)

        if x is not None and y is not None and theta is not None:
            success = execute_navigation_command(x, y, theta)
            if success != 1:
                print("Exiting loop due to failure in navigation command.")
                break
        else:
            print("Skipping navigation due to invalid pose data.")
        

if __name__ == "__main__":
    main()
