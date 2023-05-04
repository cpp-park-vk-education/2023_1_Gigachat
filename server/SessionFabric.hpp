#pragma once

#include <memory>

#include "ISessionFabric.hpp"

class IAuthorizer;

using IAuthorizerShPtr = std::shared_ptr<IAuthorizer>;

class SessionFabric : public ISessionFabric {
public:
    virtual void startSession(tcp::socket socket) override;
    virtual void endSession(User user) override;
    virtual std::set<Session> getSessions() const override;

private:
    std::set<Session> _sessions;
    IAuthorizerShPtr _authorizer;
};
