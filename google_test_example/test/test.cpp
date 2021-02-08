#include <gtest/gtest.h>
#include <ros/ros.h>
#include "talker.hpp"

int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  ros::init(argc, argv, "tester");
  ros::NodeHandle nodehandle;
  return RUN_ALL_TESTS();
}