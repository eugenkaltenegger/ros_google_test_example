// Copyright 2021 Eugen Kaltenegger

#ifndef NON_VIRTUAL_TALKER_H
#define NON_VIRTUAL_TALKER_H

#include <ros/ros.h>
#include <std_msgs/String.h>

namespace non_virtually
{
template<typename T>
class Talker
{
private:
  T *publisher_pointer;

public:
  void setPublisher(T *publisher)
  {
    this->publisher_pointer = publisher;
  };

  virtual void publish(const std_msgs::String &message) const
  {
    ROS_DEBUG("non-virtual publish function is invoked");
    this->publisher_pointer->publish(message);
  };
};
}  // namespace non_virtually

#endif  // NON_VIRTUAL_TALKER_H
