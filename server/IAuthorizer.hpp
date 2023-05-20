#pragma once

class User;

class IAuthorizer {
public:
    virtual bool authorize(User user) = 0;
};
