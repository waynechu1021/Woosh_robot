import rclpy
from rclpy.node import Node
import math
from geometry_msgs.msg import PoseStamped
from nav2_simple_commander.robot_navigator import BasicNavigator, TaskResult

class BasicNavClient(Node):
    def __init__(self):
        super().__init__('basic_nav_client')
        self._client = BasicNavigator()
        self.code2msg = {
            0: 'undefined.',
            1: 'success.',
            -1: 'fail.',
            -2: 'canceled.',
            2: 'still excuting',
            3: 'paused',
            4: 'paused failed',
            5: 'excuting failed'
        }
    

    def send_goal(self, x : float, y : float, theta : float, frame_id="map"):
        self._client.waitUntilNav2Active() # if autostarted, else use `lifecycleStartup()`
        goal_pose = PoseStamped()
        goal_pose.header.frame_id = 'map'
        goal_pose.header.stamp = self.get_clock().now().to_msg()
        goal_pose.pose.position.x = x
        goal_pose.pose.position.y = y
        goal_pose.pose.position.z = 0.0

        goal_pose.pose.orientation.x = 0.0
        goal_pose.pose.orientation.y = 0.0
        goal_pose.pose.orientation.z = math.sin(theta / 2)
        goal_pose.pose.orientation.w = math.cos(theta / 2)

        go_to_pose_task = self._client.goToPose(goal_pose)
        while not self._client.isTaskComplete():
            feedback = self._client.getFeedback()
            if feedback.navigation_time.sec > 120:
                self._client.cancelTask()

        result_holder = {
            'success_flag': None,
            'msg': None,
            'code': None
        }

        result = self._client.getResult()
        task = 'nav to pose '
        if result == TaskResult.SUCCEEDED:
            code = 1
            result_holder['code'] = code
            result_holder['success_flag'] = True
            result_holder['msg'] = task + self.code2msg[code]
        elif result == TaskResult.CANCELED:
            code = -2
            result_holder['code'] = code
            result_holder['success_flag'] = False
            result_holder['msg'] = task + self.code2msg[code]
        elif result == TaskResult.FAILED:
            code = -1
            result_holder['code'] = code
            result_holder['success_flag'] = False
            result_holder['msg'] = task + self.code2msg[code]
        

        return result_holder['success_flag'], result_holder['msg'], result_holder['code']


    def send_set_pose_request(self, x : float, y : float, theta : float):
        init_pose = PoseStamped()
        init_pose.header.frame_id = 'map'
        init_pose.header.stamp = self.get_clock().now().to_msg()
        init_pose.pose.position.x = x
        init_pose.pose.position.y = y
        init_pose.pose.position.z = 0.0

        init_pose.pose.orientation.x = 0.0
        init_pose.pose.orientation.y = 0.0
        init_pose.pose.orientation.z = math.sin(theta / 2)
        init_pose.pose.orientation.w = math.cos(theta / 2)
        self._client.setInitialPose(init_pose)
        return True, "Init success!", 1
