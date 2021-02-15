// Copyright 2021 Eugen Kaltenegger

#include <gtest/gtest.h>
#include <ros/ros.h>

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  ros::init(argc, argv, "tester");
  ros::NodeHandle nodehandle;
  // execute all tests defined in CMakeLists.txt
  return RUN_ALL_TESTS();
}
