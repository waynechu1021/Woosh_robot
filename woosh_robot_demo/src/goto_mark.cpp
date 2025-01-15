#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "std_msgs/msg/string.hpp"
#include "woosh_robot_msgs/action/exec_task.hpp"
#include "woosh_robot_msgs/msg/operation_state.hpp"
#include "woosh_robot_msgs/msg/operation_state_robot_bit.hpp"
#include "woosh_robot_msgs/srv/operation_state.hpp"

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  /// ros2 run woosh_robot_demo goto_mark
  auto node = rclcpp::Node::make_shared("goto_mark");

  // 订阅机器人‘是否可接任务’状态
  bool is_taskable = false;
  auto qos = rclcpp::QoS(rclcpp::KeepLast(1)).transient_local();
  auto rostate_sub =
      node->create_subscription<woosh_robot_msgs::msg::OperationState>(
          "woosh_robot/robot/OperationState", qos,
          [&](woosh_robot_msgs::msg::OperationState::UniquePtr ostate) {
            RCLCPP_INFO(node->get_logger(),
                        "机器人运行状态更新, nav: %d, robot: %d", ostate->nav,
                        ostate->robot);
            is_taskable =
                ostate->robot &
                woosh_robot_msgs::msg::OperationStateRobotBit::K_TASKABLE;
            if (is_taskable) {
              RCLCPP_INFO(node->get_logger(), "机器人可接任务.");
            } else {
              RCLCPP_INFO(node->get_logger(), "机器人不可接任务.");
            }
          });

  // call action

  auto exec_task_cli =
      rclcpp_action::create_client<woosh_robot_msgs::action::ExecTask>(
          node, "woosh_robot/robot/ExecTask");
  while (not exec_task_cli->wait_for_action_server(std::chrono::seconds(1))) {
    if (not rclcpp::ok()) {
      RCLCPP_ERROR(node->get_logger(), "等待服务异常!");
      return 1;
    }
    RCLCPP_INFO(node->get_logger(), "等待服务出现...");
  }
  RCLCPP_INFO(node->get_logger(), "ExecTask Action!");

  // 任务执行过程回调
  auto goal_options = rclcpp_action::Client<
      woosh_robot_msgs::action::ExecTask>::SendGoalOptions();
  goal_options.feedback_callback =
      [&node](rclcpp_action::ClientGoalHandle<
                  woosh_robot_msgs::action::ExecTask>::SharedPtr,
              const std::shared_ptr<
                  const woosh_robot_msgs::action::ExecTask::Feedback>
                  feedback) {
        auto task_proc = feedback->fb;
        RCLCPP_INFO(node->get_logger(),
                    "任务进度更新, 目的地: %s, 动作: %d, 动作状态: "
                    "%d, 任务状态: %d",
                    task_proc.dest.c_str(), task_proc.action.type.value,
                    task_proc.action.state.value, task_proc.state.value);
        if (task_proc.state.value ==
            woosh_task_msgs::msg::State::K_ACTION_WAIT) {
          RCLCPP_INFO(node->get_logger(), "Feedback: 进入等待.");
        }
      };

  // 任务执行结果
  goal_options.result_callback =
      [&node](
          rclcpp_action::ClientGoalHandle<woosh_robot_msgs::action::ExecTask>::
              WrappedResult wrapped_result) {
        switch (wrapped_result.code) {
          case rclcpp_action::ResultCode::SUCCEEDED:
            break;
          case rclcpp_action::ResultCode::ABORTED:
            RCLCPP_WARN(node->get_logger(), "任务异常结束");
          case rclcpp_action::ResultCode::CANCELED:
            RCLCPP_WARN(node->get_logger(), "任务被取消");
          default:
            RCLCPP_WARN(node->get_logger(), "未知错误");
        }

        auto task_proc = wrapped_result.result->ret;
        if (task_proc.state.value == woosh_task_msgs::msg::State::K_COMPLETED) {
          RCLCPP_INFO(node->get_logger(), "Result: 任务完成.");
        } else if (task_proc.state.value ==
                   woosh_task_msgs::msg::State::K_CANCELED) {
          RCLCPP_INFO(node->get_logger(), "Result: 任务取消.");
        } else if (task_proc.state.value ==
                   woosh_task_msgs::msg::State::K_FAILED) {
          RCLCPP_INFO(node->get_logger(), "Result: 任务失败.");
        }
      };

  // 任务执行应答
  goal_options.goal_response_callback =
      [&node](rclcpp_action::ClientGoalHandle<
              woosh_robot_msgs::action::ExecTask>::SharedPtr goal_handle) {
        if (not goal_handle) {
          RCLCPP_ERROR(node->get_logger(), "请求被服务拒绝!");
        } else {
          RCLCPP_INFO(node->get_logger(), "任务执行请求成功, 等待任务执行完成");
        }
      };

  // 订阅目标点
  /// ros2 topic pub /goto_mark/go std_msgs/msg/String "{data: A1}" --once
  auto subscription_ = node->create_subscription<std_msgs::msg::String>(
      "goto_mark/go", 10, [&](std_msgs::msg::String::UniquePtr msg) {
        // 请求参数
        auto goal = woosh_robot_msgs::action::ExecTask::Goal();
        std::string mark_no = msg->data;
        RCLCPP_INFO(node->get_logger(), "goto: '%s'", mark_no.c_str());
        goal.arg.task_id = node->now().seconds();  // 任务ID
        goal.arg.type.value = 1;                   // 任务类型
        goal.arg.direction.value = 0;              // 动作方向
        goal.arg.task_type_no = 0;                 // 动作组合
        goal.arg.mark_no = mark_no;                // 目标点储位号
        exec_task_cli->async_send_goal(goal, goal_options);
      });

  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
