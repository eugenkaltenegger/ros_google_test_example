// Copyright 2021 Eugen Kaltenegger

#include "../include/gtest_gmock_example/virtual_talker.h"

void virtually::Talker::setPublisher(virtually::Publisher* virtual_publisher)
{
  this->virtual_publisher = virtual_publisher;
}

void virtually::Talker::publish(const std_msgs::String& message) const
{
  ROS_DEBUG("virtual publish function is invoked");
  this->virtual_publisher->publish(message);
}
