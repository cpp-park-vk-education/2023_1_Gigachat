#pragma once
#include <boost/asio>

using boost::asio::tcp

class MessageHandler : IHandler{
    virtual void handle() override;
}
