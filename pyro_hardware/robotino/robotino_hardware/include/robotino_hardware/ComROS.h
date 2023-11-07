#pragma once

#include "rec/robotino/api2/Com.h"

#include <rclcpp/rclcpp.hpp>
#include <chrono>
#include <functional>
#include <memory>
#include <string>

class ComROS: public rec::robotino::api2::Com, public rclcpp::Node
{
public:
	ComROS();
	~ComROS();

	void init(const std::string& address);

private:
	rclcpp::TimerBase::SharedPtr timer_;

	void processCallback();

	void errorEvent( const char* errorString );
	void connectedEvent();
	void connectionClosedEvent();
};