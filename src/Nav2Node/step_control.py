import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient

from woosh_ros_msgs.action import StepControl
from woosh_ros_msgs.msg import StepControl as StepControlArg, ControlAction, StepControlStep, StepControlStepMode
from threading import Event

from nav2_msgs.action import NavigateToPose, Spin, BackUp
from nav2_msgs.srv import ClearEntireCostmap, GetCostmap

class StepControlClient(Node):
    def __init__(self):
        super().__init__('step_control_client')
        self._client = ActionClient(self, StepControl, '/woosh_robot/ros/StepControl')
        self.task = 'StepControl '
        self.code2msg = {
            0: self.task + 'undefined.',
            1: self.task + 'success.',
            -1: self.task + 'fail.',
            -2: self.task + 'canceled.',
            2: self.task + 'still excuting',
            3: self.task + 'paused',
            4: self.task + 'paused failed',
            5: self.task + 'excuting failed'
        }

    def send_goal(self, mode: int, value: float, speed: float = 0.5):
        '''
        Args:
            mode:   1 - forward/backward
                    2 - rotate
            value:  indicate `distance` when `mode == 1` and 'angle' when `model == 2`
            speed:  linear speed or angular speed, default to `0.5`
        '''
        goal_msg = StepControl.Goal()

        mode = StepControlStepMode(value = mode)
        step = StepControlStep(value = value, speed = speed)
        step.mode = mode

        step_arg = StepControlArg(avoid = 1)
        action = ControlAction(value = 1)
        step_arg.action = action
        step_arg.steps = [step]

        goal_msg.arg = step_arg

        self._client.wait_for_server()

        self.get_logger().info('Sending step control goal...')
        self._send_goal_future = self._client.send_goal_async(
            goal_msg,
            feedback_callback=self.feedback_callback
        )

        done_event = Event()
        result_holder = {
            'success_flag': None,
            'msg': None,
            'code': None
        }
        def goal_done_callback(send_goal_future):
            goal_handle = send_goal_future.result()
            if not goal_handle.accepted:
                result_holder['success_flag'] = False
                result_holder['msg'] = 'Goal rejected'
                result_holder['code'] = -1
                done_event.set()
                return
            result_future = goal_handle.get_result_async()

            def result_done(result_fut):
                result = result_fut.result().result
                code = result.ret.state.value
                result_holder['code'] = code
                result_holder['success_flag'] = code == 1
                result_holder['msg'] = self.code2msg[code]
                done_event.set()
            result_future.add_done_callback(result_done)

        self._send_goal_future.add_done_callback(goal_done_callback)

        done_event.wait()
        return result_holder['success_flag'], result_holder['msg'], result_holder['code']

    def feedback_callback(self, feedback_msg):
        self.get_logger().info(f'Received step control feedback: {feedback_msg.feedback}')

