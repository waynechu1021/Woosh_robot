import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry
from transforms3d.euler import quat2euler
from rclpy.qos import qos_profile_sensor_data
from tf2_ros import Buffer, TransformListener
import math

class PoseSpeedClient(Node):
    def __init__(self):
        super().__init__('get_pose_speed_client')
        self.subscription = self.create_subscription(
            Odometry,
            '/odom',
            self.odom_callback,
            qos_profile_sensor_data)
        self.odom_data = None

        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)
        
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

        # pos = self.odom_data.pose.pose.position
        # ori = self.odom_data.pose.pose.orientation
        # q = [ori.x, ori.y, ori.z, ori.w]
        # _, _, yaw = quat2euler(q)

        # position = [pos.x, pos.y, yaw]

        trans = self.tf_buffer.lookup_transform(
                'map',      
                'base_footprint',     
                self.get_clock().now(), 
                timeout=rclpy.duration.Duration(seconds=1.0)
            )

        x = trans.transform.translation.x
        y = trans.transform.translation.y
        q = trans.transform.rotation

        siny_cosp = 2 * (q.w * q.z + q.x * q.y)
        cosy_cosp = 1 - 2 * (q.y * q.y + q.z * q.z)
        yaw = math.atan2(siny_cosp, cosy_cosp)

        position = [x, y, yaw]

        linear = self.odom_data.twist.twist.linear
        angular = self.odom_data.twist.twist.angular
        speed = [linear.x, angular.z]

        result_holder['current_position'] = position
        result_holder['current_speed'] = speed

        return result_holder['current_position'], result_holder['current_speed']
