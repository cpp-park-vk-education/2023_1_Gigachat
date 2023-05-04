#pragma once

#include <utility>

class json;
class Response;

class IHandlerManager {
public:
    virtual void sendToHandler() = 0;

private:
    virtual std::pair<size_t, json> parse(Response);
};