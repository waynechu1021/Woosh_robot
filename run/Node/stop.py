import rclpy
from rclpy.node import Node
from action_msgs.srv import CancelGoal
from threading import Event

class StopClient(Node):
    def __init__(self):
        super().__init__('cancel_goal_client')
        self.cli = self.create_client(CancelGoal, '/woosh_robot/ros/MoveBase/_action/cancel_goal')
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Waiting for cancel_goal service...')

    def send_cancel_request(self):
        request = CancelGoal.Request()
        request.goal_info.goal_id.uuid = [0] * 16

        future = self.cli.call_async(request)
        
        done_event = Event()
        result_holder = {
            'success_flag': None,
            'msg': None,
            'code': None
        }
        def result_done_callback(fut):
            if fut is not None:
                if fut.result().return_code == 0:
                    result_holder['msg'] = "Stop service call success."
                    result_holder['code'] = 1
                    result_holder['success_flag'] = True
                else:
                    result_holder['msg'] = "Stop service call failed."
                    result_holder['code'] = -1
                    result_holder['success_flag'] = False
            else:
                result_holder['msg'] = "Stop service call failed."
                result_holder['code'] = -2
                result_holder['success_flag'] = False
            done_event.set()
        future.add_done_callback(result_done_callback)

        done_event.wait()
        return result_holder['success_flag'], result_holder['msg'], result_holder['code']
