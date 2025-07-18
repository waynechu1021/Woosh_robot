import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
from rclpy.qos import qos_profile_sensor_data
import numpy as np

class LidarScanClient(Node):
    def __init__(self):
        super().__init__('lidar_subscriber')
        self.subscription = self.create_subscription(
            LaserScan,
            '/scan',
            self.lidar_callback,
            qos_profile_sensor_data)
        self.lidar = None

    def lidar_callback(self, msg):
        self.lidar = msg.ranges
    
    def send_get_lidar_request(self):
        if self.lidar is None:
            self.get_logger().warn("No lidar data in the given time!")
            return None
        return np.array(self.lidar)

