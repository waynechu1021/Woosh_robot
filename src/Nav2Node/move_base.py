import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
import math
from woosh_ros_msgs.action import MoveBase
from woosh_common_msgs.msg import Pose2D
from woosh_ros_msgs.msg import MoveBase as MoveBaseArg, MoveBaseExecutionMode, ControlAction
from nav2_msgs.action import NavigateToPose
from geometry_msgs.msg import PoseStamped
from threading import Event

class MoveBaseClient(Node):
    def __init__(self):
        super().__init__('move_base_client')
        self._client = ActionClient(self, NavigateToPose, 'navigate_to_pose')
        self.task = 'NavigateToPose '
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

    def send_goal(self, x : float, y : float, theta : float, frame_id="map"):
        goal_msg = NavigateToPose.Goal()

        goal_msg.pose.header.frame_id = frame_id
        goal_msg.pose.header.stamp = self.get_clock().now().to_msg()
        
        goal_msg.pose.pose.position.x = float(x)
        goal_msg.pose.pose.position.y = float(y)
        goal_msg.pose.pose.position.z = 0.0

        goal_msg.pose.pose.orientation.x = x
        goal_msg.pose.pose.orientation.y = y
        goal_msg.pose.pose.orientation.z = math.sin(theta / 2)
        goal_msg.pose.pose.orientation.w = math.cos(theta / 2)
        
        self._client.wait_for_server()

        self.get_logger().info('Sending movebase goal...')
        future = self._client.send_goal_async(
            goal_msg,
            feedback_callback=self.feedback_callback
        )
        
        result_holder = {
            'success_flag': None,
            'msg': None,
            'code': None
        }

        rclpy.spin_until_future_complete(self, future)

        goal_handle = future.result()
        if not goal_handle.accepted:
            result_holder['success_flag'] = False
            result_holder['msg'] = 'Goal rejected'
            result_holder['code'] = -1

        result_future = goal_handle.get_result_async()
        rclpy.spin_until_future_complete(self, result_future)

        result = result_future.result().result
        print(f'result = {result}')
        code = 1
        result_holder['code'] = code
        result_holder['success_flag'] = code == 1
        result_holder['msg'] = self.code2msg[code]

        return result_holder['success_flag'], result_holder['msg'], result_holder['code']

    # def send_goal(self, x : float, y : float, theta : float, frame_id="map"):
    #     goal_msg = NavigateToPose.Goal()

    #     goal_msg.pose.header.frame_id = frame_id
    #     goal_msg.pose.header.stamp = self.get_clock().now().to_msg()
        
    #     goal_msg.pose.pose.position.x = float(x)
    #     goal_msg.pose.pose.position.y = float(y)
    #     goal_msg.pose.pose.position.z = 0.0

    #     goal_msg.pose.pose.orientation.x = x
    #     goal_msg.pose.pose.orientation.y = y
    #     goal_msg.pose.pose.orientation.z = math.sin(theta / 2)
    #     goal_msg.pose.pose.orientation.w = math.cos(theta / 2)
        
    #     self._client.wait_for_server()

    #     self.get_logger().info('Sending movebase goal...')
    #     future = self._client.send_goal_async(
    #         goal_msg,
    #         feedback_callback=self.feedback_callback
    #     )
        
    #     done_event = Event()
    #     result_holder = {
    #         'success_flag': None,
    #         'msg': None,
    #         'code': None
    #     }
    #     def goal_done_callback(send_goal_future):
    #         goal_handle = send_goal_future.result()
    #         if not goal_handle.accepted:
    #             result_holder['success_flag'] = False
    #             result_holder['msg'] = 'Goal rejected'
    #             result_holder['code'] = -1
    #             done_event.set()
    #             return
            
    #         result_future = goal_handle.get_result_async()

    #         def result_done(result_fut):
    #             result = result_fut.result().result
    #             code = result.ret.state.value
    #             result_holder['code'] = code
    #             result_holder['success_flag'] = code == 1
    #             result_holder['msg'] = self.code2msg[code]
    #             done_event.set()
    #         result_future.add_done_callback(result_done)

    #     future.add_done_callback(goal_done_callback)

    #     done_event.wait()
    #     return result_holder['success_flag'], result_holder['msg'], result_holder['code']


    def feedback_callback(self, feedback_msg):
        self.get_logger().info(f'Received movebase feedback: {feedback_msg.feedback}')



def main(args=None):
    rclpy.init(args=args)
    node = MoveBaseClient()
    node.send_goal(x = -0.66, y = -0.64, theta = 0)
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == '__main__':
    main()