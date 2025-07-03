from rclpy.node import Node
from woosh_robot_msgs.srv import SetProgramMute
from woosh_robot_msgs.msg import SetProgramMute as SetProgramMuteArg
from threading import Event


class MuteClient(Node):
    def __init__(self):
        super().__init__('mute_robot')
        self.cli = self.create_client(SetProgramMute, '/woosh_robot/robot/SetProgramMute')
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Waiting for mute service...')

    def send_mute_request(self, mute = True):
        request = SetProgramMute.Request()
        
        arg = SetProgramMuteArg()
        arg.mute = mute
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
