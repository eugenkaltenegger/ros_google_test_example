// Copyright 2021 Eugen Kaltenegger

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory>
#include "../include/gtest_gmock_example/virtual_talker.h"

namespace virtually
{
class MockPublisher : public Publisher
{
public:
    MOCK_METHOD(void, publish, (const std_msgs::String&), (const, override));
};
}

TEST(VirtualTalkerTest, verifyPublisherCall)
{
    auto mockPublisher = std::make_shared<virtually::MockPublisher>();
    auto talker = std::make_shared<virtually::Talker>();
    talker->setPublisher(mockPublisher.get());

    EXPECT_CALL(*mockPublisher.get(), publish(testing::_)).Times(1);
    std_msgs::String message;
    talker->publish(message);
}
