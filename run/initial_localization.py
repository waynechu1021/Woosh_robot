import cv2
import numpy as np
import open3d as o3d
import subprocess
import re
import time
import matplotlib.pylab as plt
from sklearn.neighbors import NearestNeighbors
o3d.utility.set_verbosity_level(o3d.utility.VerbosityLevel.Debug)

resolution = 0.05  # each pixel -> real distance
# origin = [-6.884753227233887, -23.146076202392578, 0.0]  # the point of left down
origin = [-29.641035598313977, -11.984327112417178, 0]
map_path = '/home/wayne/workspace/run/map_mid360_editted.png'
map_img = cv2.imread(map_path, cv2.IMREAD_GRAYSCALE)
angle_min = -2.1999948024749756
angle_max = 2.1999948024749756

def world_to_pixel(world_coords):
    x, y = world_coords
    pixel_x = (x - origin[0]) / resolution
    pixel_y = map_img.shape[0] - (y - origin[1]) / resolution # the Coordinate system of cv2 located in the left top
    return pixel_x, pixel_y

def pixel_to_world(pixel_coords):
    px, py = pixel_coords
    world_x = px * resolution + origin[0]
    world_y = (map_img.shape[0] - py)* resolution + origin[1]
    return world_x, world_y

def rotation_matrix_to_angle(R):
    theta_rad = np.arctan2(R[1, 0], R[0, 0])
    return theta_rad

def voxel_down_sample(pcd, voxel_size):
    try:
        pcd_down = pcd.voxel_down_sample(voxel_size)
    except:
        # for opend3d 0.7 or lower
        pcd_down = o3d.geometry.voxel_down_sample(pcd, voxel_size)
    return pcd_down

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

def load_map_and_extract_edges(map_img):
    """加载 PNG 地图并提取边缘点"""
    edges = cv2.Canny(map_img, 50, 150)  # Canny 边缘检测
    
    # Find the coordinates of the edge points
    y_idxs, x_idxs = np.where(edges > 0) # in opencv axis
    edge_points = np.column_stack((x_idxs, y_idxs)).astype(np.float32)
    edge_points = np.concatenate([edge_points,np.zeros((edge_points.shape[0],1))],axis=1)
    # 转换为 Open3D 点云格式
    map_pcd = o3d.geometry.PointCloud()
    map_pcd.points = o3d.utility.Vector3dVector(edge_points)
    return map_pcd

def convert_lidar_scan_to_pcd(laser_scan):
    """将 2D 激光雷达扫描数据转换为 Open3D 点云"""
    laser_scan = np.array(laser_scan)
    angles = np.linspace(initial_position[-1] + angle_min, initial_position[-1] + angle_max, len(laser_scan))  # 角度范围
    indice = np.where( (laser_scan!=np.inf)  &(laser_scan < 30) & (laser_scan > 0.05))
    x = laser_scan * np.cos(angles) + initial_position[0]
    y = laser_scan * np.sin(angles) + initial_position[1]
    x = x[indice]
    y = y[indice]
    x, y = world_to_pixel([x,y])
    plt.figure()
    plt.axis('off')
    plt.imshow(map_img,cmap='gray')
    plt.scatter(x,y,s =15)
    plt.savefig('test.jpg',dpi=200)
    lidar_points = np.vstack((x, y)).T
    lidar_points = np.concatenate([lidar_points,np.zeros((lidar_points.shape[0],1))],axis=1)
    
    lidar_pcd = o3d.geometry.PointCloud()
    lidar_pcd.points = o3d.utility.Vector3dVector(lidar_points)
    return lidar_pcd

def icp_registration(source, target, threshold=2.0, init_transformation=np.eye(4)):
    """使用 ICP 进行点云匹配"""
    icp_result = o3d.pipelines.registration.registration_icp(
        voxel_down_sample(source, 0.05 * threshold), voxel_down_sample(target, 0.01 * threshold), threshold, init_transformation,
        o3d.pipelines.registration.TransformationEstimationPointToPoint(),
        o3d.pipelines.registration.ICPConvergenceCriteria(max_iteration=20)
    )
    return icp_result.transformation, icp_result.fitness

def preprocess_point_cloud(pcd, voxel_size):
    pcd_down = pcd.voxel_down_sample(voxel_size)
    pcd_down.estimate_normals(o3d.geometry.KDTreeSearchParamHybrid(radius=voxel_size * 2, max_nn=30))
    fpfh = o3d.pipelines.registration.compute_fpfh_feature(
        pcd_down, o3d.geometry.KDTreeSearchParamHybrid(radius=voxel_size * 5, max_nn=100)
    )
    return pcd_down, fpfh

def ransac_global_registration(source, target, voxel_size=0.4):
    source_down, source_fpfh = preprocess_point_cloud(source, voxel_size)
    target_down, target_fpfh = preprocess_point_cloud(target, voxel_size)

    result = o3d.pipelines.registration.registration_ransac_based_on_feature_matching(
        source_down, target_down, source_fpfh, target_fpfh, voxel_size * 1.5,
        estimation_method=o3d.pipelines.registration.TransformationEstimationPointToPoint(),
        ransac_n=4,
        checkers=[
            o3d.pipelines.registration.CorrespondenceCheckerBasedOnEdgeLength(0.9),
            o3d.pipelines.registration.CorrespondenceCheckerBasedOnDistance(voxel_size * 1.5)
        ],
        criteria=o3d.pipelines.registration.RANSACConvergenceCriteria(100000, 0.999)
    )
    return result.transformation

def main(laser_scan, initial_position):
    #initial_position = [0, 0, -0.6495510935783386]
    print(f"initial position = {initial_position}")
    """主函数：加载地图、转换激光数据并进行 ICP 匹配"""
    map_pcd = load_map_and_extract_edges(map_img)  # 提取地图边缘点云
    lidar_pcd = convert_lidar_scan_to_pcd(laser_scan)  # 转换激光雷达数据

    map_pcd.estimate_normals(
        search_param=o3d.geometry.KDTreeSearchParamHybrid(radius=0.1 * 2, max_nn=30)
    )
    lidar_pcd.estimate_normals(
        search_param=o3d.geometry.KDTreeSearchParamHybrid(radius=0.1 * 2, max_nn=30)
    )

    # 运行 ICP 进行配准
    init_trans = np.eye(4)  # 初始变换矩阵
    # transform, fitness = icp_registration(lidar_pcd, map_pcd, threshold=5, init_transformation=init_trans)
    transform = ransac_global_registration(lidar_pcd, map_pcd)
    transform, fitness = icp_registration(lidar_pcd, map_pcd, threshold=0.01, init_transformation=transform)
    
    # 获取匹配的坐标
    shift = transform[:2, -1]  # 取平移部分作为机器人在地图上的坐标
    rotation_transform = transform[:2,:2]
    # position = shift + np.array(world_to_pixel([initial_position[0],initial_position[1]]))
    position = np.dot(rotation_transform, np.array(world_to_pixel([initial_position[0],initial_position[1]]))) + shift
    position_world = pixel_to_world(position)
    
    roration_theta = rotation_matrix_to_angle(rotation_transform) + initial_position[-1]
    print(f"ICP transformation matrix = {transform}")
    print(f"robot location in world axis: x = {position_world[0]:.2f}, y = {position_world[1]:.2f}")
    print(f'theta = {roration_theta}')
    print(f'fitness = {fitness}')
    return position_world

# 示例调用
if __name__ == "__main__":
    ros2_process = subprocess.Popen(
    ["ros2", "run", "woosh_robot_agent", "agent",
     "--ros-args", "-r", "__ns:=/woosh_robot", "-p", 'ip:="169.254.128.2"'],
    stdout=subprocess.PIPE,
    stderr=subprocess.PIPE,
    text=True
)

    # 等待一会儿，确保 ROS 2 节点启动
    time.sleep(5)
    map_file = 'map_mid360_editted.png'
    lidar_scan, initial_position = get_lidar() #size of 1411
    main(lidar_scan, initial_position)