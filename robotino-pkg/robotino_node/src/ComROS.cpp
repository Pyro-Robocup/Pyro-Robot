#include "robotino_node/ComROS.h"

ComROS::ComROS()
	: thread_(&ComROS::processCallback, this)
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
}

void ComROS::processCallback()
{
	std::lock_guard<std::mutex> lock(mutex_);
	this->processEvents();
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
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
