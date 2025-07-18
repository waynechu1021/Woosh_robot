from rclpy.node import Node
from threading import Event
from geometry_msgs.msg import Twist
import time

class StepControlClient(Node):
    def __init__(self):
        super().__init__('step_control_client')
        self.publisher = self.create_publisher(Twist, '/cmd_vel', 10)
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

    def send_goal(self, distance=1.0, speed=0.2):
        '''
        Args:
            mode:   1 - forward/backward
                    2 - rotate
            value:  indicate `distance` when `mode == 1` and 'angle' when `model == 2`
            speed:  linear speed or angular speed, default to `0.5`
        '''

        msg = Twist()
        msg.linear.x = speed if distance > 0 else -speed
        duration = abs(distance) / speed

        start_time = time.time()
        while time.time() - start_time < duration:
            self.publisher.publish(msg)
            time.sleep(0.1)

        # stop move
        msg.linear.x = 0.0
        self.publisher.publish(msg)

        result_holder = {
            'success_flag': True,
            'msg': 'success.',
            'code': 1
        }
        return result_holder['success_flag'], result_holder['msg'], result_holder['code']

