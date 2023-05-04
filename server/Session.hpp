#pragma once

#include <memory>

#include <boost/asio.hpp>

#include "ISessionFabric.hpp"
#include "User.hpp"

class IHandlerManager;
class ResponseManager;

using boost::asio::ip::tcp;
using IHandlerManagerShPtr = std::shared_ptr<IHandlerManager>;
using ISessionFabricShPtr = std::shared_ptr<ISessionFabric>

class Session {
public:

private:
    void doReadRequest();
    void doSendResponse();
    void sendRequestTohandler();

    tcp::socket _socket;
    User _user;
    IHandlerManagerShPtr _requestManager;
    ResponseManager _reaponseManager;
    ISessionFabricShPtr _fabric;
};
