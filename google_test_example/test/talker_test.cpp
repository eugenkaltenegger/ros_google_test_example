#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <ros/ros.h>
#include "talker.hpp"

class MockPublisher : public ros::Publisher {
    public:
         MOCK_METHOD(void, publish, (std_msgs::String message), ());
};

// TODO: check naming convention for test suit and test case
TEST(TalkerTest, verifyPublisherCall) {
    MockPublisher* mockPublisher = new MockPublisher();
    Talker* talker = new Talker(mockPublisher);
    std_msgs::String message;
    talker->publish(message);
    EXPECT_CALL(*mockPublisher, publish(message)).Times(1);
}