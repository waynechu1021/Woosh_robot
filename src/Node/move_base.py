import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient

from woosh_ros_msgs.action import MoveBase
from woosh_common_msgs.msg import Pose2D
from woosh_ros_msgs.msg import MoveBase as MoveBaseArg, MoveBaseExecutionMode, ControlAction
from threading import Event

class MoveBaseClient(Node):
    def __init__(self):
        super().__init__('move_base_client')
        self._client = ActionClient(self, MoveBase, '/woosh_robot/ros/MoveBase')
        self.task = 'MoveBase '
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

    def send_goal(self, x : float, y : float, theta : float):
        goal_msg = MoveBase.Goal()

        mode = MoveBaseExecutionMode(value = 1)
        poses = Pose2D(x = x, y = y, theta = theta)

        move_base_arg = MoveBaseArg()
        action = ControlAction(value = 1)
        move_base_arg.action = action
        move_base_arg.poses = [poses]
        move_base_arg.target_pose = poses
        move_base_arg.execution_mode = mode

        goal_msg.arg = move_base_arg

        self._client.wait_for_server()

        self.get_logger().info('Sending movebase goal...')
        future = self._client.send_goal_async(
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

        future.add_done_callback(goal_done_callback)

        done_event.wait()
        return result_holder['success_flag'], result_holder['msg'], result_holder['code']


    def feedback_callback(self, feedback_msg):
        self.get_logger().info(f'Received movebase feedback: {feedback_msg.feedback}')

