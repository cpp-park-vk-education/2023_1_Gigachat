#pragma once

#include <set>

#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class User;
class Session;

class ISessionFabric {
public:
    virtual void startSession(tcp::socket socket) = 0;
    virtual void endSession(User user) = 0;
    virtual std::set<Session> getSessions() const = 0;
};
