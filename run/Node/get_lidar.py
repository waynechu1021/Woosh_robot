import rclpy
from rclpy.node import Node
from woosh_robot_msgs.srv import ScannerData
from threading import Event
import numpy as np


class LidarScanClient(Node):
    def __init__(self):
        super().__init__('get_lidar_client')
        self.cli = self.create_client(ScannerData, '/woosh_robot/robot/ScannerData')
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Waiting for lidar scan service...')

    def send_get_lidar_request(self):
        request = ScannerData.Request()

        future = self.cli.call_async(request)

        done_event = Event()
        result_holder = {
            'ranges_list': None,
            'initial_state': None,
        }
        def result_done_callback(fut):
            if fut.result() is not None:
                result_holder['initial_state'] = [fut.result().ret.pose.x, fut.result().ret.pose.y, fut.result().ret.pose.theta]
                result_holder['ranges_list'] = np.array(fut.result().ret.ranges)
            done_event.set()
        future.add_done_callback(result_done_callback)

        done_event.wait()
        return result_holder['ranges_list'], result_holder['initial_state']
