cmake_minimum_required(VERSION 3.8)
project(woosh_robot_demo)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(woosh_robot_msgs REQUIRED)
find_package(woosh_ros_msgs REQUIRED)
find_package(std_msgs REQUIRED)

# monitor
add_executable(monitor src/monitor.cpp)
target_include_directories(monitor PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/${PROJECT_NAME}>)
target_compile_features(monitor PUBLIC c_std_99 cxx_std_17)
ament_target_dependencies(monitor rclcpp woosh_robot_msgs)

# exectask
add_executable(exectask src/exectask.cpp)
target_include_directories(exectask PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/${PROJECT_NAME}>)
target_compile_features(exectask PUBLIC c_std_99 cxx_std_17)
ament_target_dependencies(exectask rclcpp rclcpp_action woosh_robot_msgs)

# stepctrl
add_executable(stepctrl src/stepctrl.cpp)
target_include_directories(stepctrl PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/${PROJECT_NAME}>)
target_compile_features(stepctrl PUBLIC c_std_99 cxx_std_17)
ament_target_dependencies(stepctrl rclcpp rclcpp_action woosh_ros_msgs)

# exec_pre_task
add_executable(exec_pre_task src/exec_pre_task.cpp)
target_include_directories(exec_pre_task PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/${PROJECT_NAME}>)
target_compile_features(exec_pre_task PUBLIC c_std_99 cxx_std_17)
ament_target_dependencies(exec_pre_task rclcpp woosh_robot_msgs)

# init_robot
add_executable(init_robot src/init_robot.cpp)
target_include_directories(init_robot PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/${PROJECT_NAME}>)
target_compile_features(init_robot PUBLIC c_std_99 cxx_std_17)
ament_target_dependencies(init_robot rclcpp woosh_robot_msgs)

# goto_mark
add_executable(goto_mark src/goto_mark.cpp)
target_include_directories(goto_mark PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/${PROJECT_NAME}>)
target_compile_features(goto_mark PUBLIC c_std_99 cxx_std_17)
ament_target_dependencies(goto_mark rclcpp rclcpp_action woosh_robot_msgs std_msgs)

# movebase_goal
add_executable(movebase_goal src/movebase_goal.cpp)
target_include_directories(movebase_goal PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/${PROJECT_NAME}>)
target_compile_features(movebase_goal PUBLIC c_std_99 cxx_std_17)
ament_target_dependencies(movebase_goal rclcpp rclcpp_action woosh_ros_msgs woosh_common_msgs)

# install
install(TARGETS monitor DESTINATION lib/${PROJECT_NAME})
install(TARGETS exectask DESTINATION lib/${PROJECT_NAME})
install(TARGETS stepctrl DESTINATION lib/${PROJECT_NAME})
install(TARGETS exec_pre_task DESTINATION lib/${PROJECT_NAME})
install(TARGETS init_robot DESTINATION lib/${PROJECT_NAME})
install(TARGETS goto_mark DESTINATION lib/${PROJECT_NAME})
install(TARGETS movebase_goal DESTINATION lib/${PROJECT_NAME})

ament_package()
