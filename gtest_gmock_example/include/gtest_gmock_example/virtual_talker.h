// Copyright 2021 Eugen Kaltenegger

#ifndef VIRTUAL_TALKER_H
#define VIRTUAL_TALKER_H

#include <ros/ros.h>
#include <std_msgs/String.h>
#include "./virtual_publisher.h"

namespace virtually
{
class Talker
{
private:
  virtually::Publisher* virtual_publisher = nullptr;

public:
  void setPublisher(virtually::Publisher* virtual_publisher);
  virtual void publish(const std_msgs::String& message) const;
};
}  // namespace virtually
#endif  // VIRTUAL_TALKER_H
