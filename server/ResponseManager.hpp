#pragma once

#include <queue>

#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class Response;

class ResponseManager {
public:
    void doWrite();

private:
    tcp::socket _socket;
    std::queue<Response> _responses;
};