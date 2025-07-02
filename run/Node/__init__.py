from .get_lidar import LidarScanClient
from .get_pose_speed import PoseSpeedClient
from .move_base import MoveBaseClient
from .step_control import StepControlClient
from .stop import StopClient
from .init_robot import InitRobotClient
from .mute import MuteClient
from .set_pose import SetPoseClient


from rclpy.executors import MultiThreadedExecutor
import rclpy, math
from threading import Thread
import numpy as np
import logging


class NodeManager:
    def __init__(self):
        rclpy.init() 
        self.executor = MultiThreadedExecutor()

        self.get_lidar_client = LidarScanClient()
        self.get_pose_speed_client = PoseSpeedClient()
        self.move_base_client = MoveBaseClient()
        self.step_control_client = StepControlClient()
        self.stop_client = StopClient()
        self.init_robot_client = InitRobotClient()
        self.mute_robot_client = MuteClient()
        self.set_pose_client = SetPoseClient()
        
        self.executor.add_node(self.get_lidar_client)
        self.executor.add_node(self.get_pose_speed_client)
        self.executor.add_node(self.move_base_client)
        self.executor.add_node(self.step_control_client)
        self.executor.add_node(self.stop_client)
        self.executor.add_node(self.init_robot_client)
        self.executor.add_node(self.mute_robot_client)
        self.executor.add_node(self.set_pose_client)

        executor_thread = Thread(target=self.executor.spin, daemon=True)
        executor_thread.start()

    def forward(self, distance):
        success_flag,info,state = self.step_control_client.send_goal(mode = 1, value = distance)
        return success_flag,info,state

    def rotate(self, theta):
        success_flag,info,state = self.step_control_client.send_goal(mode = 2, value = theta)
        return success_flag,info,state

    def shift(self, distance):
        success_flag,info,state = self.step_control_client.send_goal(mode = 3, value = distance)
        return success_flag,info,state

    def navigation(self, x, y, theta):
        # get lidar data first
        lidar_scan, _ = self.get_lidar_client.send_get_lidar_request()
        angles = np.linspace(-2.1999948024749756, 2.1999948024749756, len(lidar_scan))  # 角度范围
        indice = np.where( (angles >= -math.pi/4) & (angles <= math.pi/4))
        lidar_scan = lidar_scan[indice]
        lidar_scan = lidar_scan[~np.isnan(lidar_scan)]
        lidar_scan = lidar_scan[np.isfinite(lidar_scan)]
        min_lidar_distance = np.min(lidar_scan)
        while min_lidar_distance < 0.4:
            logging.warning("The obstacle is too close, back off!")
            self.forward(distance = -0.3)
            lidar_scan, _ = self.get_lidar_client.send_get_lidar_request()
            angles = np.linspace(-2.1999948024749756, 2.1999948024749756, len(lidar_scan))  # 角度范围
            indice = np.where( (angles >= -math.pi/4) & (angles <= math.pi/4))
            lidar_scan = lidar_scan[indice]
            lidar_scan = lidar_scan[~np.isnan(lidar_scan)]
            lidar_scan = lidar_scan[np.isfinite(lidar_scan)]
            min_lidar_distance = np.min(lidar_scan)

        success_flag,info,state = self.move_base_client.send_goal(float(x), float(y), float(theta))
        return success_flag,info,state

    def stop(self,):
        success_flag,info,state = self.stop_client.send_cancel_request()
        return success_flag,info,state
    
    def get_lidar(self):
        ranges_list, initial_state = self.get_lidar_client.send_get_lidar_request()
        return ranges_list, initial_state

    def get_pose_speed(self):
        current_position,current_speed = self.get_pose_speed_client.send_get_pose_request()
        return current_position,current_speed
    
    def init_robot(self, x = 0.018, y = 0.0254, theta = -3.064):
        success_flag,info,state = self.init_robot_client.send_init_robot_request(float(x), float(y), float(theta))
        return success_flag,info,state
    
    def mute(self, mute = True):
        success_flag,info,state = self.mute_robot_client.send_mute_request(mute)
        return success_flag,info,state
    
    def set_pose(self, x, y, theta):
        success_flag,info,state = self.set_pose_client.send_set_pose_request(float(x), float(y), float(theta))
        return success_flag,info,state

    def destroy_all_node(self):
        self.get_lidar_client.destroy_node()
        self.get_pose_speed_client.destroy_node()
        self.move_base_client.destroy_node()
        self.step_control_client.destroy_node()
        self.stop_client.destroy_node()

        self.executor.shutdown()
        rclpy.shutdown()


# node = NodeManager()
# success_flag,info,state = node.init_robot()
# node.move_base_client.send_goal(x = 0.78,y = -0.09, theta = 0.)
# node.stop_client.send_cancel_request()
# print(success_flag,info,state)
# node.destroy_all_node()
