#ifndef MAIN_H
#define MAIN_H

#include <std_msgs/String.h>
#include <ros/ros.h>
#include <sstream>

#include "talker.hpp"

std_msgs::String getStringMessage();

#endif