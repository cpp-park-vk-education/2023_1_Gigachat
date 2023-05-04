#pragma once
#include <boost/asio>

class Client{
private:
    User _user;
    shared_prt<IMessageListener> _listener;

    void doListen() const;
    void connectToServer() const;
public:
    //esatblish connection with server and creates listener object 
    Client(boost::asio::tcp::socket)
    void send() const;
};
