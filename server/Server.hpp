#pragma once

#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class Sever {
public:
    void doAccept();

private:
    tcp::acceptor _acceptor;
};
