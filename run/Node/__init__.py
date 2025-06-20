from .get_lidar import LidarScanClient
from .get_pose_speed import PoseSpeedClient
from .move_base import MoveBaseClient
from .step_control import StepControlClient
from .stop import StopClient


from rclpy.executors import MultiThreadedExecutor
import rclpy
from threading import Thread


class NodeManager:
    def __init__(self):
        rclpy.init() 
        self.executor = MultiThreadedExecutor()

        self.get_lidar_client = LidarScanClient()
        self.get_pose_speed_client = PoseSpeedClient()
        self.move_base_client = MoveBaseClient()
        self.step_control_client = StepControlClient()
        self.stop_client = StopClient()
        
        self.executor.add_node(self.get_lidar_client)
        self.executor.add_node(self.get_pose_speed_client)
        self.executor.add_node(self.move_base_client)
        self.executor.add_node(self.step_control_client)
        self.executor.add_node(self.stop_client)

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

    def destroy_all_node(self):
        self.get_lidar_client.destroy_node()
        self.get_pose_speed_client.destroy_node()
        self.move_base_client.destroy_node()
        self.step_control_client.destroy_node()
        self.stop_client.destroy_node()

        self.executor.shutdown()
        rclpy.shutdown()


# node = NodeManager()
# node.step_control_client.send_goal(mode = 1, value = -1.5)
# node.move_base_client.send_goal(x = 0.78,y = -0.09, theta = 0.)
# node.stop_client.send_cancel_request()
# node.destroy_all_node()
