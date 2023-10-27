#include "robotino_node/OmniDriveROS.h"

OmniDriveROS::OmniDriveROS()
	: Node("omnidrive_node")
{
	cmd_vel_sub_ = this->create_subscription<geometry_msgs::msg::TwistStamped>(
		"cmd_vel", 1, std::bind(&OmniDriveROS::cmdVelCallback, this, std::placeholders::_1));
}

OmniDriveROS::~OmniDriveROS()
{
	
}

void OmniDriveROS::cmdVelCallback(const geometry_msgs::msg::TwistStamped::SharedPtr msg)
{
	double linear_x = msg->twist.linear.x;
	double linear_y = msg->twist.linear.y;
	double angular = msg->twist.angular.z;

	if ( fabs( linear_x ) > max_linear_vel_ )
	{
		if( linear_x > 0.0 )
			linear_x = max_linear_vel_;
		else
			linear_x = -max_linear_vel_;
	}
	else if( fabs( linear_x ) <  min_linear_vel_ && fabs( linear_x ) > 0.0 )
	{
		if( linear_x > 0.0 )
			linear_x = min_linear_vel_;
		else
			linear_x = -min_linear_vel_;
	}

	if ( fabs( linear_y ) > max_linear_vel_ )
	{
		if( linear_y > 0.0 )
			linear_y = max_linear_vel_;
		else
			linear_y = -max_linear_vel_;
	}
	else if( fabs( linear_y ) <  min_linear_vel_ && fabs( linear_y ) > 0.0 )
	{
		if( linear_y > 0.0 )
			linear_y = min_linear_vel_;
		else
			linear_y = -min_linear_vel_;
	}

	if ( fabs( angular ) > max_angular_vel_ )
	{
		if( angular > 0.0 )
			angular = max_angular_vel_;
		else
			angular = -max_angular_vel_;
	}
	else if( fabs( angular ) <  min_angular_vel_ && fabs( angular ) > 0.0 )
	{
		if( angular > 0.0 )
			angular = min_angular_vel_;
		else
			angular = -min_angular_vel_;
	}

	setVelocity( linear_x, linear_y, angular);
}

void OmniDriveROS::setMaxMin( double max_linear_vel, double min_linear_vel, double max_angular_vel, double min_angular_vel )
{
	max_linear_vel_ = max_linear_vel;
	min_linear_vel_ = min_linear_vel;
	max_angular_vel_ = max_angular_vel;
	min_angular_vel_ = min_angular_vel;
}
