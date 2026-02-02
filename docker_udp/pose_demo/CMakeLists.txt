cmake_minimum_required(VERSION 3.8)
project(pose_demo)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)

add_executable(pose_publisher src/pose_publisher.cpp)
ament_target_dependencies(pose_publisher rclcpp geometry_msgs)

add_executable(pose_subscriber src/pose_subscriber.cpp)
ament_target_dependencies(pose_subscriber rclcpp geometry_msgs)

install(TARGETS
  pose_publisher
  pose_subscriber
  DESTINATION lib/${PROJECT_NAME})

ament_package()
