// Copyright 2021 Eugen Kaltenegger

#include "../include/gtest_gmock_example/virtual_publisher.h"

void virtually::Publisher::setPublisher(ros::Publisher* publisher)
{
  this->publisher_pointer = publisher;
}

void virtually::Publisher::publish(const std_msgs::String& message) const
{
  this->publisher_pointer->publish(message);
}

