#ifndef NON_VIRTUAL_TALKER_H
#define NON_VIRTUAL_TALKER_H

#include <ros/ros.h>
#include <std_msgs/String.h>

namespace NonVirtual { ;

    template<typename T>
    class Talker {

        private:
            T *publisher_pointer;

        public:

            void setPublisher(T *publisher) {
                this->publisher_pointer = publisher;
            };

            virtual void publish(const std_msgs::String &message) const {
                ROS_DEBUG("non-virtual publish function is invoked");
                this->publisher_pointer->publish(message);
            };

    };
}

#endif // NON_VIRTUAL_TALKER_H