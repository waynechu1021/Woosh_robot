#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "woosh_ros_msgs/action/move_base.hpp"

// clang-format off
/// ros2 cli command:
/// ros action send_goal /woosh_robot/ros/StepControl woosh_ros_msgs/action/StepControl "{arg:{action:{value: 1}, steps:[{mode:{value: 2}, speed: 1, value: 3}]}}" --feedback
/// action.value: 0 -> 取消
/// action.value: 1 -> 执行
/// action.value: 2 -> 暂停
/// action.value: 3 -> 继续
/// mode.value: 1 -> 直行
/// mode.value: 2 -> 旋转
/// mode.value: 3 -> 横移
/// mode.value: 4 -> 斜移
/// speed: folat -> 角速度[弧度/s]/线速度[米/s]
/// value: float -> 旋转弧度/行驶距离, 正前负后, 正逆负顺, 正左负右
/// angle: float -> 斜向运动角度, 正左负右
// clang-format on

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);

  // clang-format off
  /// ros2 run woosh_robot_demo stepctrl --ros-args -p mode:=1 -p action:=1 -p speed:=0.2 -p value:=0.5
  // clang-format on
  auto node = rclcpp::Node::make_shared("movebase_goal");
//   node->declare_parameter("x", 0.2f);
//   float_t x = node->get_parameter("x").as_double();
//   node->declare_parameter("y", 0.2f);
//   float_t y = node->get_parameter("y").as_double();
//   node->declare_parameter("theta", 0.2f);
//   float_t theta = node->get_parameter("theta").as_double();
  node->declare_parameter("t_x", 0.2f);
  float_t t_x = node->get_parameter("t_x").as_double();
  node->declare_parameter("t_y", 0.2f);
  float_t t_y = node->get_parameter("t_y").as_double();
  node->declare_parameter("t_theta", 0.2f);
  float_t t_theta = node->get_parameter("t_theta").as_double();

//   RCLCPP_INFO(node->get_logger(),
//               "poses x: %f, poses y: %f, poses theta: %f, target pose x: %f, target pose y: %f, target pose theta: %f", x,
//               y, theta, t_x, t_y, t_theta);
  RCLCPP_INFO(node->get_logger(),
              "target pose x: %f, target pose y: %f, target pose theta: %f", t_x, t_y, t_theta);

  // call action

  auto exec_task_cli =
      rclcpp_action::create_client<woosh_ros_msgs::action::MoveBase>(
          node, "woosh_robot/ros/MoveBase");
  if (!exec_task_cli->wait_for_action_server(std::chrono::seconds(20))) {
    RCLCPP_ERROR(node->get_logger(), "等待服务超时!");
    return 1;
  }

  // 请求参数
  auto send_goal = woosh_ros_msgs::action::MoveBase::Goal();
  woosh_common_msgs::msg::Pose2D poses;
  poses.x = t_x;
  poses.y = t_y;
  poses.theta = t_theta;
  send_goal.arg.poses.push_back(poses);

  send_goal.arg.target_pose.x = t_x;
  send_goal.arg.target_pose.y = t_y;
  send_goal.arg.target_pose.theta = t_theta;

  send_goal.arg.execution_mode.value = 1;

  // 步进过程回调
  auto send_goal_options = rclcpp_action::Client<
      woosh_ros_msgs::action::MoveBase>::SendGoalOptions();
  send_goal_options.feedback_callback =
      [&node](rclcpp_action::ClientGoalHandle<
                  woosh_ros_msgs::action::MoveBase>::SharedPtr,
              const std::shared_ptr<
                  const woosh_ros_msgs::action::MoveBase::Feedback>
                  feedback) {
        woosh_ros_msgs::msg::Feedback fb = feedback->fb;
        RCLCPP_INFO(node->get_logger(),
                    "Movebase状态更新, 状态: %d, 状态码: %ld, 消息: %s",
                    fb.state.value, fb.code, fb.msg.c_str());
      };

  // 步进执行请求
  auto goal_handle_future =
      exec_task_cli->async_send_goal(send_goal, send_goal_options);
  if (rclcpp::spin_until_future_complete(node, goal_handle_future) !=
      rclcpp::FutureReturnCode::SUCCESS) {
    RCLCPP_ERROR(node->get_logger(), "Movebase请求失败!");
    return 1;
  }

  rclcpp_action::ClientGoalHandle<
      woosh_ros_msgs::action::MoveBase>::SharedPtr goal_handle =
      goal_handle_future.get();
  if (!goal_handle) {
    RCLCPP_ERROR(node->get_logger(), "请求被服务拒绝!");
    return 1;
  }

  // 等待步进执行结果
  auto result_future = exec_task_cli->async_get_result(goal_handle);
  if (rclcpp::spin_until_future_complete(node, result_future) !=
      rclcpp::FutureReturnCode::SUCCESS) {
    RCLCPP_ERROR(node->get_logger(), "获取结果失败!");
    return 1;
  }

  rclcpp_action::ClientGoalHandle<
      woosh_ros_msgs::action::MoveBase>::WrappedResult wrapped_result =
      result_future.get();

  switch (wrapped_result.code) {
    case rclcpp_action::ResultCode::SUCCEEDED:
      break;
    case rclcpp_action::ResultCode::ABORTED:
      RCLCPP_WARN(node->get_logger(), "Movebase异常结束");
    case rclcpp_action::ResultCode::CANCELED:
      RCLCPP_WARN(node->get_logger(), "Movebase被取消");
    default:
      RCLCPP_WARN(node->get_logger(), "未知错误");
  }

  auto task_proc = wrapped_result.result->ret;
  if (task_proc.state.value == woosh_ros_msgs::msg::State::K_ROS_SUCCESS) {
    RCLCPP_INFO(node->get_logger(), "Result: 步进完成.");
  } else if (task_proc.state.value ==
             woosh_ros_msgs::msg::State::K_ROS_CANCEL) {
    RCLCPP_INFO(node->get_logger(), "Result: 步进取消.");
  } else if (task_proc.state.value ==
             woosh_ros_msgs::msg::State::K_ROS_FAILURE) {
    RCLCPP_INFO(node->get_logger(), "Result: 步进失败.");
  }

  exec_task_cli.reset();
  node.reset();
  rclcpp::shutdown();
  return 0;
}
