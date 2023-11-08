#include "robotino_hardware/OdometryROS.h"

OdometryROS::OdometryROS()
	: Node("odometry_node")
{
	this->setComId(rec::robotino::api2::ComId());
}

OdometryROS::~OdometryROS()
{
	
}