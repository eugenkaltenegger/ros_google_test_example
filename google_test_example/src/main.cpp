#include "main.hpp"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");
  ros::NodeHandle nodehandle;
  ros::Publisher talker_publisher = nodehandle.advertise<std_msgs::String>("talker", 1000);
  ros::Rate loop_rate(10);

  Talker* talker = new Talker(&talker_publisher);

  while (ros::ok())
  {
    talker->publish(getStringMessage());

    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}

std_msgs::String getStringMessage() {
    static int message_count = 0;
    std_msgs::String message;
    
    std::stringstream string_stream;
    string_stream << "I have told you to write tests " << message_count << " times!";
    message.data = string_stream.str();

    message_count++;

    return message;
}