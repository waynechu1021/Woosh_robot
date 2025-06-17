import open3d as o3d
import numpy as np
import cv2
import yaml
"""

功能:将mesh数据转换为2D占用栅格地图(高度为z轴,mesh一般比较规整,一次投影)
主要步骤：
1. mesh转点云数据
2. 采样和过滤孤立点
3. 生成2D占用栅格地图(白色)
5. 过滤出障碍区域的点,投影黑色到白色幕布上
6. 处理小区域（去除噪点）
7. 保存为ROS格式的地图文件
"""
# 配置参数
file_directory = "/home/phw/newdisk1/vpr_data/yunkeji/"  
file_name = "textured_mesh"
pcd_file = file_directory + file_name + ".obj"


map_resolution = 0.05
thre_z_min =  0.2#保留点云的最低高度:readpoint_height[0] +0.15获得
thre_z_max =  1.8#保留点云的最高高度，单位m
thre_radius = 0.1 #半径滤波 单位m
thres_point_count = 3 #半径滤波的个数 
min_area_count = 20 #去除黑色小点点的最小黑色面积



def remove_black_regions(A, min_area=min_area_count):
    """
    处理矩阵 A:去除小的黑色区域，反转颜色。
    
    参数:
        A: 输入的二值矩阵，假设黑色为前景，白色为背景
        min_area: 最小面积阈值，用于去除小区域
        
    返回:
        processed_image: 处理后的图像
    """
    # 反转颜色（确保黑色是前景）
    _, binary = cv2.threshold(A, 127, 255, cv2.THRESH_BINARY_INV)

    # 计算连通域并去除小的黑色区域
    num_labels, labels, stats, _ = cv2.connectedComponentsWithStats(binary, connectivity=8)

    # 遍历连通区域，去除小面积的黑色区域
    for i in range(1, num_labels):  # 从1开始，跳过背景
        if stats[i, cv2.CC_STAT_AREA] < min_area:
            binary[labels == i] = 0  # 将小区域置为白色

    # 反转回原色
    processed_image = cv2.bitwise_not(binary)
    
    return processed_image


def remove_white_regions(A, min_area=min_area_count):
    """
    处理矩阵 A:去除小的白色区域。
    参数:
        A: 输入的二值矩阵，假设白色为前景，黑色为背景
        min_area: 最小面积阈值，用于去除小区域
        
    返回:
        processed_image: 处理后的图像
    """
    # 反转颜色（确保黑色是前景）
    binary = A.copy()

    # 计算连通域并去除小的黑色区域
    num_labels, labels, stats, _ = cv2.connectedComponentsWithStats(binary, connectivity=8)

    # 遍历连通区域，去除小面积的黑色区域
    for i in range(1, num_labels):  # 从1开始，跳过背景
        if stats[i, cv2.CC_STAT_AREA] < min_area:
            binary[labels == i] = 255  # 将小区域置为白色
    
    return binary

# 读取PCD文件
# pcd = o3d.io.read_point_cloud(pcd_file)
mesh = o3d.io.read_triangle_mesh(pcd_file)
# 检查mesh是否有效
if not mesh.has_vertices():
    print("Error: Mesh has no vertices")
    exit()

# 可选：修复mesh（如果mesh有问题）
# mesh.remove_degenerate_triangles()  # 移除退化的三角形
# mesh.remove_duplicated_triangles()  # 移除重复的三角形
# mesh.remove_duplicated_vertices()   # 移除重复的顶点
# mesh.remove_non_manifold_edges()    # 移除非流形边

# 将mesh转换为点云
pcd = mesh.sample_points_uniformly(number_of_points=10000000)  # 均匀采样
# pcd = pcd.voxel_down_sample(voxel_size=0.01)  # 从0.05改为0.1
# pcd, _ = pcd.remove_radius_outlier(nb_points=5, radius=0.1) 
points = np.asarray(pcd.points)



points = points[(points[:, 2] >= thre_z_min-0.5) & (points[:, 2] <= thre_z_max + 2)]
# print(points.shape)


# 创建Open3D点云对象
cloud_after_filter = o3d.geometry.PointCloud()
cloud_after_filter.points = o3d.utility.Vector3dVector(points)
# o3d.visualization.draw_geometries([cloud_after_filter], window_name='black')
#半径滤波
# print(len(cloud_after_filter.points))
# cloud_after_filter = radius_outlier_filter(cloud_after_filter, thre_radius, thres_point_count)
points_after_filter = np.asarray(cloud_after_filter.points)
# print(points_after_filter.shape)
# 获取点云的最小最大值
x_min, y_min = np.min(points_after_filter[:, :2], axis=0)
x_max, y_max = np.max(points_after_filter[:, :2], axis=0)

# 计算栅格地图大小
map_width = int((x_max - x_min) / map_resolution)
map_height = int((y_max - y_min) / map_resolution)
# 初始化栅格地图
occupancy_grid = np.zeros((map_height, map_width), dtype=np.uint8)
occupancy_grid.fill(255)
# for point in points_after_filter:
#     x, y = point[:2]
#     # 转换为栅格坐标
#     i = int((x - x_min) / map_resolution)
#     j = int((y - y_min) / map_resolution)
#     # 确保索引在地图范围内
#     if 0 <= i < map_width and 0 <= j < map_height:
#         occupancy_grid[j, i] = 255  # 设置为区域底色：白色（255）


# # map_image_ros = np.flipud(occupancy_grid)  # 反转行
# # map_image_bgr = cv2.cvtColor(map_image_ros, cv2.COLOR_GRAY2BGR)
# # # 保存为 .png 文件
# # cv2.imwrite(file_directory + file_name + "0.png", map_image_bgr)
# occupancy_grid = remove_black_regions(occupancy_grid)
# print(occupancy_grid.shape)

# cv2.imwrite(file_directory + file_name + "1.png", np.flipud(occupancy_grid))
##
# 二次处理：白色区域加上障碍区域
##
# 直通滤波：移除Z轴不在指定范围内的点
points_after_filter = points_after_filter[(points_after_filter[:, 2] >= thre_z_min) & (points_after_filter[:, 2] <= thre_z_max)]
for point in points_after_filter:
    x, y = point[:2]
    i = int((x - x_min) / map_resolution)
    j = int((y - y_min) / map_resolution)
    if 0 <= i < map_width and 0 <= j < map_height:
        occupancy_grid[j, i] = 0  # 黑色
occupancy_grid = remove_white_regions(occupancy_grid)
# print(occupancy_grid.shape)
# cv2.imwrite(file_directory + file_name + "2.png", np.flipud(occupancy_grid))

# 翻转y轴（ros左下角为原点，opencv左上角为原点）
map_image_ros = np.flipud(occupancy_grid)  # 反转行
map_image_bgr = cv2.cvtColor(map_image_ros, cv2.COLOR_GRAY2BGR)

# 保存为 .png 文件
# cv2.imwrite(file_directory + file_name + ".png", map_image_bgr)
cv2.imwrite(file_directory +"map.png", map_image_bgr)
origin = str([float(x_min), float(y_min), 0.0])
# 保存YAML文件的字典
map_yaml = {
    "image":  "map.png",
    "resolution": map_resolution,
    # "mode": "trinary",
    "origin": origin,
    "negate": 0,
    "occupied_thresh": 0.65,
    "free_thresh": 0.196
    # "height": map_height,
    # "width": map_width
}


# with open(file_directory + file_name + ".yaml", 'w') as yaml_file:
with open(file_directory + "map" + ".yaml", 'w') as yaml_file:
    yaml.dump(map_yaml, yaml_file, default_flow_style=False, sort_keys=False)

# 读取并处理文件，确保 origin 为单行
with open(file_directory + "map" + ".yaml", 'r') as yaml_file:
    yaml_data = yaml_file.read()

# 替换 origin 格式为单行
yaml_data = yaml_data.replace("'", '')

# 写回文件
with open(file_directory + "map" + ".yaml", 'w') as yaml_file:
    yaml_file.write(yaml_data)

print("Map saved as map.png and map.yaml")
