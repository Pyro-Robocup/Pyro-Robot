#include "rclcpp/rclcpp.hpp"
#include "robotino_node/OmniDriveROS.h"

int main(int argc, char** argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<OmniDriveROS>();

  rclcpp::spin(node);

  rclcpp::shutdown();
  return 0;
}