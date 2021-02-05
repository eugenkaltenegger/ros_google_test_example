#ifndef TALKER_H
#define TALKER_H

#include <ros/ros.h>
#include <std_msgs/String.h>

class Talker {
    public:
        Talker();
        Talker(ros::Publisher* publisher);
        //~Talker();
        void setPublisher(ros::Publisher* publisher); 
        void publish(std_msgs::String);
    private:
        ros::Publisher* publisher_pointer;

};

#endif