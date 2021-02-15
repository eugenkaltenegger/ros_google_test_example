#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "virtual_talker.hpp"
#include "virtual_publisher.hpp"

namespace Virtual {
class MockPublisher : public Publisher {
public:
    MOCK_METHOD(void, publish, (const std_msgs::String&), (const, override));
};
}

TEST(VirtualTalkerTest, verifyPublisherCall) {
    auto mockPublisher = std::make_shared<Virtual::MockPublisher>();
    auto talker = std::make_shared<Virtual::Talker>();
    talker->setPublisher(mockPublisher.get());

    EXPECT_CALL(*mockPublisher.get(), publish(testing::_)).Times(1);
    std_msgs::String message;
    talker->publish(message);
}