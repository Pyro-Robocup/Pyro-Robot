#include "robotino_node/ComROS.h"
#include <iostream>

ComROS::ComROS()
{
}

ComROS::~ComROS()
{
	if (thread_.joinable()) 
	{
		thread_.join();
	}
}

void ComROS::init(const std::string& name,  const std::string& address)
{
	name_ = name;
	this->setAddress(address.c_str());
	this->connectToServer(false);
	thread_ = std::thread(&ComROS::processCallback, this);
}

void ComROS::processCallback()
{
	this->processEvents();
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	std::cout << "looped" << std::endl;
	RCLCPP_INFO(rclcpp::get_logger(name_), "callback for processing occured");
}

void ComROS::errorEvent( const char* errorString )
{
	RCLCPP_ERROR(rclcpp::get_logger(name_), errorString);
}

void ComROS::connectedEvent()
{
	RCLCPP_INFO(rclcpp::get_logger(name_), "connected to Robotino");
}

void ComROS::connectionClosedEvent()
{
	RCLCPP_INFO(rclcpp::get_logger(name_), "disconnected from Robotino");
}
