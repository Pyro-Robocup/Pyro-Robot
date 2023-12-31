cmake_minimum_required(VERSION 3.8)
project(robotino_hardware)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
set(CMAKE_MODULE_PATH /opt/robotino/cmake)

find_package(ament_cmake REQUIRED)
find_package(robotino_msgs REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(RobotinoAPI2)

include_directories(include)

add_executable(omnidrive_node
  src/OmniDriveROS.cpp)

add_executable(com_node
  src/ComROS.cpp)

target_link_libraries(
  omnidrive_node
  ${REC_ROBOTINO_API2_LIBRARY}
)

target_link_libraries(
  com_node
  ${REC_ROBOTINO_API2_LIBRARY}
)

ament_target_dependencies(omnidrive_node rclcpp geometry_msgs)
ament_target_dependencies(com_node rclcpp)


install(TARGETS
  omnidrive_node
  com_node
  DESTINATION lib/${PROJECT_NAME})

ament_package()
