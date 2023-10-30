#pragma once

#include "rec/robotino/api2/Com.h"

#include "rclcpp/rclcpp.hpp"
#include <string>

class ComROS: public rec::robotino::api2::Com
{
public:
	ComROS();
	~ComROS();

	void setName( const std::string& name );

private:
	std::string name_;

	void errorEvent( const char* errorString );
	void connectedEvent();
	void connectionClosedEvent();
};