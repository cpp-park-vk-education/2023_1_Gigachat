#pragma once
#include <boost/asio>

using boost::asio::tcp; 

class ResponseListener{
private:
    socket _socket;
    shared_prt<IHandlerManager> _manager; 

    void sendCallbackToManager();
public:
    void doListen();
};
