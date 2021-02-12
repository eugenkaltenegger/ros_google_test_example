#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "non_virtual_talker.hpp"

namespace NonVirtual {
    class MockPublisher {
        public:
            MOCK_METHOD(void, publish, (const std_msgs::String&), (const));
    };    
}

TEST(NonVirtualTalkerTest, verifyPublisherCall) {
    auto mockPublisher = std::make_shared<NonVirtual::MockPublisher>();
    auto talker = std::make_shared<NonVirtual::Talker<NonVirtual::MockPublisher>>();
    talker->setPublisher(mockPublisher.get());
    
    EXPECT_CALL(*mockPublisher.get(), publish(testing::_)).Times(1);
    std_msgs::String message;
    talker->publish(message);
}

