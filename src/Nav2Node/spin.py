# from rclpy.node import Node
# from rclpy.action import ActionClient
# import math
# from nav2_msgs.action import Spin
# from geometry_msgs.msg import PoseStamped
# from threading import Event
# from builtin_interfaces.msg import Duration


# class SpinClient(Node):
#     def __init__(self):
#         super().__init__('spin_client')
#         self._client = ActionClient(self, Spin, 'spin')
#         self.task = 'Spin '
#         self.code2msg = {
#             0: self.task + 'undefined.',
#             1: self.task + 'success.',
#             -1: self.task + 'fail.',
#             -2: self.task + 'canceled.',
#             2: self.task + 'still excuting',
#             3: self.task + 'paused',
#             4: self.task + 'paused failed',
#             5: self.task + 'excuting failed'
#         }

#     def send_rotate(self, theta, time_allowance: int = 10,
#             disable_collision_checks: bool = False):
#         '''
#         Args:
#             theta:   float  positive -> left 
#                             negative -> right 
#         '''
#         goal_msg = Spin.Goal()
#         goal_msg.target_yaw = theta
#         goal_msg.time_allowance = Duration(sec=time_allowance)
#         goal_msg.disable_collision_checks = disable_collision_checks
        
#         self._client.wait_for_server()

#         self.get_logger().info('Sending rotate goal...')
#         future = self._client.send_goal_async(
#             goal_msg,
#         )
        
#         done_event = Event()
#         result_holder = {
#             'success_flag': None,
#             'msg': None,
#             'code': None
#         }
#         def goal_done_callback(send_goal_future):
#             goal_handle = send_goal_future.result()
#             if not goal_handle.accepted:
#                 result_holder['success_flag'] = False
#                 result_holder['msg'] = 'Goal rejected'
#                 result_holder['code'] = -1
#                 done_event.set()
#                 return
            
#             result_future = goal_handle.get_result_async()

#             def result_done(result_fut):
#                 result = result_fut.result().result
#                 print(result)
#                 code = result.result
#                 result_holder['code'] = code
#                 result_holder['success_flag'] = code == 1
#                 result_holder['msg'] = self.code2msg[code]
#                 done_event.set()
#             result_future.add_done_callback(result_done)

#         future.add_done_callback(goal_done_callback)

#         done_event.wait()
#         return result_holder['success_flag'], result_holder['msg'], result_holder['code']


from rclpy.node import Node
from geometry_msgs.msg import Twist
import time

class SpinClient(Node):
    def __init__(self):
        super().__init__('rotate_control_client')
        self.publisher = self.create_publisher(Twist, '/cmd_vel', 10)
        self.task = 'RotateControl '
        self.code2msg = {
            0: self.task + 'undefined.',
            1: self.task + 'success.',
            -1: self.task + 'fail.',
            -2: self.task + 'canceled.',
            2: self.task + 'still executing',
            3: self.task + 'paused',
            4: self.task + 'pause failed',
            5: self.task + 'execution failed'
        }

    def send_rotate(self, angle=1.57, angular_speed=0.5):
        """
        Args:
            angle: rotation angle in radians (positive = left, negative = right)
            angular_speed: angular speed in rad/s
        """
        msg = Twist()
        msg.angular.z = angular_speed if angle > 0 else -angular_speed
        duration = abs(angle) / abs(angular_speed)

        start_time = time.time()
        while time.time() - start_time < duration:
            self.publisher.publish(msg)
            time.sleep(0.1)

        # stop spin
        msg.angular.z = 0.0
        self.publisher.publish(msg)

        result_holder = {
            'success_flag': True,
            'msg': self.code2msg[1],
            'code': 1
        }
        return result_holder['success_flag'], result_holder['msg'], result_holder['code']
