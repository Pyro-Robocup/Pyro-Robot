FROM osrf/ros:humble-desktop-full

RUN apt update && apt upgrade -y

RUN apt install wget net-tools -y
RUN wget -qO - http://packages.openrobotino.org/keyFile | sudo apt-key add -
RUN echo "deb http://packages2.openrobotino.org focal main" > /etc/apt/sources.list.d/openrobotino.list
RUN apt update
RUN apt install robotino-api2 rec-rpc robotino-dev

# Source the ROS humble setup file
RUN echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc

RUN apt install -y ros-humble-navigation2 ros-humble-nav2-bringup

