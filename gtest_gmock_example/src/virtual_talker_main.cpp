// Copyright 2021 Eugen Kaltenegger

#include <memory>
#include "../include/gtest_gmock_example/virtual_talker_main.h"
#include "../include/gtest_gmock_example/message_provider.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "virtual_talker");
  ros::NodeHandle nodehandle;
  ros::Publisher talker_publisher = nodehandle.advertise<std_msgs::String>("talker", 1000);
  ros::Rate loop_rate(10);

  auto publisher_wrapper = std::make_shared<virtually::Publisher>();
  publisher_wrapper->setPublisher(&talker_publisher);

  auto talker = std::make_shared<virtually::Talker>();
  talker->setPublisher(publisher_wrapper.get());

  auto messageProvider = std::make_shared<message_provider>();

  while (ros::ok())
  {
    talker->publish(messageProvider->getStringMessage());

    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}
