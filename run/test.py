import numpy as np
import cv2
from scipy.spatial import cKDTree

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


# 测试
input_coords = [4.98, -1.52]  # 输入二维坐标
# input_coords = [7.81, -3.69]  # 输入二维坐标
feasible, result_coords = is_point_feasible(input_coords)
if feasible:
    print(f"输入点 {input_coords} 在可行区域内。")
else:
    print(f"输入点 {input_coords} 不在可行区域，最近的可行点是 {result_coords}.")
    pixel_coords = world_to_pixel(result_coords)
    px, py = pixel_coords
    print(px, py)

import matplotlib.pylab as plt
plt.figure()
plt.axis('off')
plt.imshow(map_image,cmap='gray')
plt.scatter([235],[113])
plt.show()