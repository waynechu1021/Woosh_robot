import numpy as np
import open3d as o3d
from map_utils import world_to_pixel, pixel_to_world

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

def icp_registration(source, target, threshold=2.0, init_transformation=np.eye(4)):
    icp_result = o3d.pipelines.registration.registration_icp(
        voxel_down_sample(source, 0.05 * threshold), voxel_down_sample(target, 0.01 * threshold), threshold, init_transformation,
        o3d.pipelines.registration.TransformationEstimationPointToPoint(),
        o3d.pipelines.registration.ICPConvergenceCriteria(max_iteration=20)
    )
    return icp_result.transformation, icp_result.fitness

def convert_lidar_scan_to_pcd(laser_scan, position_by_vpr, map_image, origin, resolution):
    angle_min = -2.1999948024749756
    angle_max = 2.1999948024749756
    laser_scan = np.array(laser_scan)
    angles = np.linspace(position_by_vpr[-1] + angle_min, position_by_vpr[-1] + angle_max, len(laser_scan))  # 角度范围
    indice = np.where( (laser_scan!=np.inf)  &(laser_scan < 30) & (laser_scan > 0.05))
    x = laser_scan * np.cos(angles) + position_by_vpr[0]
    y = laser_scan * np.sin(angles) + position_by_vpr[1]
    x = x[indice]
    y = y[indice]
    x, y = world_to_pixel([x,y], map_image, origin, resolution)
    lidar_points = np.vstack((x, y)).T
    lidar_points = np.concatenate([lidar_points,np.zeros((lidar_points.shape[0],1))],axis=1)
    
    lidar_pcd = o3d.geometry.PointCloud()
    lidar_pcd.points = o3d.utility.Vector3dVector(lidar_points)
    return lidar_pcd

def localization_refine(map_pcd, lidar_pcd, initial_position, map_image, origin, resolution):
    init_trans = np.eye(4)
    transform, fitness = icp_registration(lidar_pcd, map_pcd, threshold=5, init_transformation=init_trans)
    # transform = ransac_global_registration(lidar_pcd, map_pcd)
    transform, fitness = icp_registration(lidar_pcd, map_pcd, threshold=1, init_transformation=transform)
    

    shift = transform[:2, -1] 
    rotation_transform = transform[:2,:2]
    # position = shift + np.array(world_to_pixel([initial_position[0],initial_position[1]]))
    position = np.dot(rotation_transform, np.array(world_to_pixel([initial_position[0],initial_position[1]], map_image, origin, resolution))) + shift
    position_world = pixel_to_world(position, map_image, origin, resolution)
    
    rotation_theta = rotation_matrix_to_angle(rotation_transform) + initial_position[-1]
    return position_world[0], position_world[1], rotation_theta