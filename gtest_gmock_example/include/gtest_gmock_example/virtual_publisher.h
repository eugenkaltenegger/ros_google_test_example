// Copyright 2021 Eugen Kaltenegger

#ifndef VIRTUAL_PUBLISHER_H
#define VIRTUAL_PUBLISHER_H

#include <ros/ros.h>
#include <std_msgs/String.h>

namespace virtually
{
class Publisher : public ros::Publisher
{
private:
  ros::Publisher *publisher_pointer;

public:
  void setPublisher(ros::Publisher *);
  virtual void publish(const std_msgs::String &) const;
};
}  // namespace virtually

#endif  // VIRTUAL_PUBLISHER_H
