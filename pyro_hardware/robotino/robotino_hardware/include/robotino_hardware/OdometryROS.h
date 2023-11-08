#pragma once

#include "rec/robotino/api2/Odometry.h"
#include "rec/robotino/api2/ComId.h"

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "nav_msgs/msg/odometry.hpp"

class OdometryROS: public rec::robotino::api2::Odometry, public rclcpp::Node
{
public:
	OdometryROS();
	~OdometryROS();

private:
	rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_sub_;
};