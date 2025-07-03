from rclpy.node import Node
from woosh_robot_msgs.srv import PoseSpeed, Scene
from threading import Event


class PoseSpeedClient(Node):
    def __init__(self):
        super().__init__('get_pose_speed_client')
        self.cli = self.create_client(PoseSpeed, '/woosh_robot/robot/PoseSpeed')
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Waiting for pose_speed service...')

    def send_get_pose_request(self):
        request = PoseSpeed.Request()

        future = self.cli.call_async(request)

        done_event = Event()
        result_holder = {
            'current_position': None,
            'current_speed': None,
        }
        def result_done_callback(fut):
            if fut.result() is not None:
                result_holder['current_position'] = [fut.result().info.pose.x, fut.result().info.pose.y, fut.result().info.pose.theta]
                result_holder['current_speed'] = [fut.result().info.twist.linear, fut.result().info.twist.angular]
            done_event.set()
        future.add_done_callback(result_done_callback)

        done_event.wait()
        return result_holder['current_position'], result_holder['current_speed']
