#pragma once

#include "rec/robotino/api2/Com.h"

#include <rclcpp/rclcpp.hpp>
#include <string>
#include <thread>
#include <chrono>

class ComROS: public rec::robotino::api2::Com
{
public:
	ComROS();
	~ComROS();

	void init(const std::string& name,  const std::string& address);

private:
	std::string name_;
	std::thread thread_;
	std::mutex mutex_;

	void processCallback();

	void errorEvent( const char* errorString );
	void connectedEvent();
	void connectionClosedEvent();
};