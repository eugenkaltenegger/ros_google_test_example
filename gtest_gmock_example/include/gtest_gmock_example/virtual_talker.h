// Copyright 2021 Eugen Kaltenegger

#ifndef VIRTUAL_TALKER_H
#define VIRTUAL_TALKER_H

#include <ros/ros.h>
#include <std_msgs/String.h>
#include "./virtual_publisher.h"

namespace Virtual
{
class Talker
{
private:
  Virtual::Publisher* virtual_publisher = nullptr;

public:
  void setPublisher(Virtual::Publisher* virtual_publisher);
  virtual void publish(const std_msgs::String& message) const;
};
}  // namespace Virtual
#endif  // VIRTUAL_TALKER_H
