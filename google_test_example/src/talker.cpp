#include "talker.hpp"

#include <sstream>

std_msgs::String getMessage() {
    static int message_count = 0;
    std_msgs::String message;
    
    std::stringstream string_stream;
    string_stream << "I have told you to write tests " << message_count << " times!";
    message.data = string_stream.str();

    message_count++;

    return message;
}

void publish(ros::Publisher* publisher) {
    std_msgs::String message = getMessage();
    ROS_INFO("%s", message.data.c_str());
    publisher->publish(message);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");
  ros::NodeHandle nodehandle;
  ros::Publisher talker_publisher = nodehandle.advertise<std_msgs::String>("talker", 1000);
  ros::Publisher* talker_publisher_pointer = &talker_publisher;
  ros::Rate loop_rate(10);

  while (ros::ok())
  {
    publish(talker_publisher_pointer);

    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}