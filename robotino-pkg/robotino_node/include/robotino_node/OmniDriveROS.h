#pragma once

#include "rec/robotino/api2/OmniDrive.h"

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "robotino_node/ComROS.h"

class OmniDriveROS: public rec::robotino::api2::OmniDrive, public rclcpp::Node
{
public:
	OmniDriveROS();
	~OmniDriveROS();

private:
	rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_sub_;
	
	double max_linear_vel_;
	double min_linear_vel_;
	double max_angular_vel_;
	double min_angular_vel_;

	void cmdVelCallback(const geometry_msgs::msg::Twist::SharedPtr msg);

public:
	void setMaxMin( double max_linear_vel, double min_linear_vel, double max_angular_vel, double min_angular_vel );
};