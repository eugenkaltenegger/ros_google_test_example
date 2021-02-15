// Copyright 2021 Eugen Kaltenegger

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory>
#include "../include/gtest_gmock_example/non_virtual_talker.h"

namespace non_virtually
{
class MockPublisher
{
public:
    MOCK_METHOD(void, publish, (const std_msgs::String&), (const));
};
}

TEST(NonVirtualTalkerTest, verifyPublisherCall)
{
  auto mockPublisher = std::make_shared<non_virtually::MockPublisher>();
  auto talker = std::make_shared<non_virtually::Talker<non_virtually::MockPublisher>>();
  talker->setPublisher(mockPublisher.get());

  EXPECT_CALL(*mockPublisher.get(), publish(testing::_)).Times(1);
  std_msgs::String message;
  talker->publish(message);
}
