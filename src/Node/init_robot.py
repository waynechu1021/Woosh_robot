import rclpy
from rclpy.node import Node
from woosh_robot_msgs.srv import InitRobot
from woosh_robot_msgs.msg import InitRobot as InitRobotArg
from woosh_common_msgs.msg import Pose2D
from threading import Event


class InitRobotClient(Node):
    def __init__(self):
        super().__init__('init_robot')
        self.cli = self.create_client(InitRobot, '/woosh_robot/robot/InitRobot')
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Waiting for init robot service...')

    def send_init_robot_request(self, x : float, y : float, theta : float):
        request = InitRobot.Request()
        
        pose = Pose2D(x = x, y = y, theta = theta)
        arg = InitRobotArg()
        arg.pose = pose
        request.arg = arg

        future = self.cli.call_async(request)

        done_event = Event()
        result_holder = {
            'success_flag': None,
            'msg': None,
            'code': None
        }
        def result_done_callback(fut):
            if fut.result() is not None:
                result_holder['msg'] = fut.result().msg
                result_holder['success_flag'] = fut.result().ok
                result_holder['code'] = 1 if result_holder['success_flag'] else -1
            done_event.set()
        future.add_done_callback(result_done_callback)

        done_event.wait()
        return result_holder['success_flag'], result_holder['msg'], result_holder['code']
