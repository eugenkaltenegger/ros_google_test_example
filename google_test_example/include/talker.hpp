#ifndef TALKER_H
#define TALKER_H

#include "ros/ros.h"
#include "std_msgs/String.h"

std_msgs::String getMessage();
void publish(ros::Publisher* publisher);

#endif 