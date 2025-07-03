import rclpy
from rclpy.node import Node
from threading import Event
from nav_msgs.msg import Odometry
from transforms3d.euler import quat2euler

class PoseSpeedClient(Node):
    def __init__(self):
        super().__init__('get_pose_speed_client')
        self.subscription = self.create_subscription(
            Odometry,
            '/odom',
            self.odom_callback,
            10)
        self.odom_data = None
        
    def odom_callback(self, msg):
        self.odom_data = msg

    def send_get_pose_request(self):
        result_holder = {
            'current_position': None,
            'current_speed': None,
        }

        if self.odom_data is None:
            self.get_logger().warn("No odom data in the given time!")
            return result_holder['current_position'], result_holder['current_speed']

        pos = self.odom_data.pose.pose.position
        ori = self.odom_data.pose.pose.orientation
        q = [ori.x, ori.y, ori.z, ori.w]
        _, _, yaw = quat2euler(q)

        position = [pos.x, pos.y, yaw]

        linear = self.odom_data.twist.twist.linear
        angular = self.odom_data.twist.twist.angular
        speed = [linear.x, angular.z]

        result_holder['current_position'] = position
        result_holder['current_speed'] = speed

        return result_holder['current_position'], result_holder['current_speed']
