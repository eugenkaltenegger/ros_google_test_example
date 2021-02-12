#ifndef VIRTUAL_TALKER_MAIN_H
#define VIRTUAL_TALKER_MAIN_H

#include <std_msgs/String.h>
#include <ros/ros.h>
#include <sstream>

#include "virtual_talker.hpp"

std_msgs::String getStringMessage();

#endif // VIRTUAL_TALKER_MAIN_H