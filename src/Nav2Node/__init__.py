from .get_lidar import LidarScanClient
from .get_pose_speed import PoseSpeedClient
from .basic_nav import BasicNavClient
from .step_control import StepControlClient
from .stop import StopClient
from .spin import SpinClient


from rclpy.executors import MultiThreadedExecutor
import rclpy
from threading import Thread


class NodeManager:
    def __init__(self):
        rclpy.init() 
        self.executor = MultiThreadedExecutor()

        self.get_lidar_client = LidarScanClient()
        self.get_pose_speed_client = PoseSpeedClient()
        self.basic_nav_client = BasicNavClient()
        self.step_control_client = StepControlClient()
        self.stop_client = StopClient()
        self.spin_client = SpinClient()
        
        self.executor.add_node(self.get_lidar_client)
        self.executor.add_node(self.get_pose_speed_client)
        self.executor.add_node(self.basic_nav_client)
        self.executor.add_node(self.step_control_client)
        self.executor.add_node(self.stop_client)
        self.executor.add_node(self.spin_client)

        executor_thread = Thread(target=self.executor.spin, daemon=True)
        executor_thread.start()

    def forward(self, distance):
        success_flag,info,state = self.step_control_client.send_goal(float(distance))
        return success_flag,info,state

    def rotate(self, theta):
        success_flag,info,state = self.spin_client.send_rotate(theta)
        return success_flag,info,state

    def set_pose(self, x, y, theta):
        success_flag,info,state = self.basic_nav_client.send_set_pose_request(float(x), float(y), float(theta))
        return success_flag,info,state 

    def navigation(self, x, y, theta):
        success_flag,info,state = self.basic_nav_client.send_goal(float(x), float(y), float(theta))
        return success_flag,info,state

    def stop(self,):
        success_flag,info,state = self.stop_client.send_cancel_request()
        return success_flag,info,state
    
    def get_lidar(self):
        ranges_list = self.get_lidar_client.send_get_lidar_request()
        return ranges_list

    def get_pose_speed(self):
        current_position,current_speed = self.get_pose_speed_client.send_get_pose_request()
        return current_position,current_speed

    def destroy_all_node(self):
        self.get_lidar_client.destroy_node()
        self.get_pose_speed_client.destroy_node()
        self.basic_nav_client.destroy_node()
        self.step_control_client.destroy_node()
        self.stop_client.destroy_node()

        self.executor.shutdown()
        rclpy.shutdown()


# node = NodeManager()
# import time
# time.sleep(2)

# # node.step_control_client.send_goal(mode = 1, value = -1.5)
# # node.navigation(x = 1.13,y = -0.03, theta = 0.65)
# # node.navigation(x = -0.78,y = -0.28, theta = 0.65)
# # node.navigation(x = 0.35,y = 1.55, theta = 0.65)
# # node.stop_client.send_cancel_request()
# # node.forward(-1)
# # node.rotate(-3.14/2)
# lidar = node.get_lidar()
# print(f"lidar = {lidar}")
# position,speed = node.get_pose_speed()
# print(f"position = {position}, speed = {speed}")
# node.destroy_all_node()
