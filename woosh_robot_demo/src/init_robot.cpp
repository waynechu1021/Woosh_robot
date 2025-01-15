#include "woosh_robot_msgs/srv/init_robot.hpp"

#include "rclcpp/rclcpp.hpp"

// clang-format off
/// ros2 cli command:
/// ros2 service call /woosh_robot/robot/InitRobot woosh_robot_msgs/srv/InitRobot "{arg:{is_record: true}}"
/// ros2 service call /woosh_robot/robot/InitRobot woosh_robot_msgs/srv/InitRobot "{arg:{pose:{x: 1.23, y: 2.34, theta: 1.57}}}"
// clang-format on

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);

  // clang-format off
  /// ros2 run woosh_robot_demo init_robot --ros-args -p is_record:=true
  /// ros2 run woosh_robot_demo init_robot --ros-args -p x:=1.23 -p y:=2.34 -p theta:=1.57
  // clang-format on
  auto node = rclcpp::Node::make_shared("init_robot");
  node->declare_parameter("is_record", false);
  bool is_record = node->get_parameter("is_record").as_bool();
  node->declare_parameter("x", 0.0f);
  float_t x = node->get_parameter("x").as_double();
  node->declare_parameter("y", 0.0f);
  float_t y = node->get_parameter("y").as_double();
  node->declare_parameter("theta", 0.0f);
  float_t theta = node->get_parameter("theta").as_double();

  auto init_robot_cli = node->create_client<woosh_robot_msgs::srv::InitRobot>(
      "woosh_robot/robot/InitRobot");
  while (not init_robot_cli->wait_for_service(std::chrono::seconds(1))) {
    if (not rclcpp::ok()) {
      RCLCPP_ERROR(node->get_logger(), "等待服务异常!");
      return 1;
    }
    RCLCPP_INFO(node->get_logger(), "等待服务出现...");
  }

  auto request = std::make_shared<woosh_robot_msgs::srv::InitRobot::Request>();
  request->arg.is_record = is_record;
  request->arg.pose.x = x;
  request->arg.pose.y = y;
  request->arg.pose.theta = theta;
  auto request_future = init_robot_cli->async_send_request(request);
  if (rclcpp::spin_until_future_complete(node, request_future) !=
      rclcpp::FutureReturnCode::SUCCESS) {
    RCLCPP_ERROR(node->get_logger(), "请求初始化机器人失败!");
    return 1;
  }

  auto request_ret = request_future.get();
  if (request_ret->ok) {
    RCLCPP_INFO(node->get_logger(), "初始化机器人请求成功, %s",
                request_ret->msg.c_str());
  } else {
    RCLCPP_INFO(node->get_logger(), "初始化机器人请求失败, %s",
                request_ret->msg.c_str());
  }

  init_robot_cli.reset();
  node.reset();
  rclcpp::shutdown();
  return 0;
}
