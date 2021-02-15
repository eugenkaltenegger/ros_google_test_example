// Copyright 2021 Eugen Kaltenegger

#include "../include/gtest_gmock_example/message_provider.h"

std_msgs::String message_provider::getStringMessage()
{
  std_msgs::String message;

  std::stringstream string_stream;
  string_stream << "I have told you to write tests " << this->messageCount << " times!";
  message.data = string_stream.str();

  this->messageCount++;

  return message;
}
