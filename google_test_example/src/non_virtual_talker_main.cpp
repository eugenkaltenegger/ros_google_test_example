// Copyright 2021 Eugen Kaltenegger

#include <memory>
#include "../include/non_virtual_talker_main.h"
#include "../include/message_provider.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "non_virtual_talker");
  ros::NodeHandle nodehandle;
  ros::Publisher talker_publisher = nodehandle.advertise<std_msgs::String>("talker", 1000);
  ros::Rate loop_rate(10);

  auto talker = std::make_shared<NonVirtual::Talker<ros::Publisher>>();
  talker->setPublisher(&talker_publisher);

  auto messageProvider = std::make_shared<MessageProvider>();

  while (ros::ok())
  {
    talker->publish(messageProvider->getStringMessage());

    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}
