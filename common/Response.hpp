// #pragma once

#include <iostream>
#include <boost/json.hpp>

class Response {
public:
    Response(const std::string& type, boost::json::value body) :
        _type(type), _body(body) {}

    std::string type() const { return _type; }
    boost::json::value body() const { return _body; }

private:
    std::string _type;
    boost::json::value _body;
};
