#ifndef VIRTUAL_PUBLISHER_H
#define VIRTUAL_PUBLISHER_H

#include <ros/ros.h>
#include <std_msgs/String.h>

namespace Virtual {

    class Publisher : public ros::Publisher {
            
        private: 
            ros::Publisher* publisher_pointer;

        public:
            void setPublisher(ros::Publisher*);
            virtual void publish(const std_msgs::String&) const;

    };
    
}

#endif // VIRTUAL_PUBLISHER_H