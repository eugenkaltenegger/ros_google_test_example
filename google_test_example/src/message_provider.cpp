#include "message_provider.hpp"

std_msgs::String MessageProvider::getStringMessage() {
    std_msgs::String message;
    
    std::stringstream string_stream;
    string_stream << "I have told you to write tests " << this->messageCount << " times!";
    message.data = string_stream.str();

    this->messageCount++;

    return message;
}