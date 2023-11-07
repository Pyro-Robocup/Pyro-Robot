#include "robotino_node/ComROS.h"

using namespace std::chrono_literals;

ComROS::ComROS()
	: Node("com_node")
{
	timer_ = this->create_wall_timer(500ms, std::bind(&ComROS::processCallback, this));
	init("127.0.1.1");
}

ComROS::~ComROS()
{

}

void ComROS::init(const std::string& address)
{
	this->setAddress(address.c_str());
	this->connectToServer(false);
}

void ComROS::processCallback()
{
	this->processEvents();
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	RCLCPP_INFO(this->get_logger(), "callback for processing occured");
}

void ComROS::errorEvent( const char* errorString )
{
	RCLCPP_ERROR(this->get_logger(), errorString);
}

void ComROS::connectedEvent()
{
	RCLCPP_INFO(this->get_logger(), "connected to Robotino");
}

void ComROS::connectionClosedEvent()
{
	RCLCPP_INFO(this->get_logger(), "disconnected from Robotino");
}

int main(int argc, char * argv[])
{
	rclcpp::init(argc, argv);

	auto node = std::make_shared<ComROS>();

	rclcpp::spin(node);

	rclcpp::shutdown();
	return 0;
}