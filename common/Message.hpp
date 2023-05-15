#pragma once

#include <string>

class Message {
private:
    size_t _id;
    std::string _from;
    std::string _to;
    std::string _timestamp;
    std::string _language;
    std::string _textData;
};
