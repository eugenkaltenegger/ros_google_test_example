#include "talker.hpp"

Talker::Talker() {
  return;
}

Talker::Talker(ros::Publisher* publisher) {
  this->publisher_pointer = publisher;
  return;
}

void Talker::setPublisher(ros::Publisher* publisher) {
  this->publisher_pointer = publisher;
}

void Talker::publish(std_msgs::String message) {
    ROS_INFO("%s", message.data.c_str());
    this->publisher_pointer->publish(message);
}