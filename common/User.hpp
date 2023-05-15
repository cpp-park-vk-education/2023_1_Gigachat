#pragma once

#include <string>

#include <boost/json/src.hpp>

class User {
public:
    User() = default;
    
    User(const std::string& login, const std::string password, const std::string nickname, const std::string& language) :
        _login(login), _password(password), _nickname(nickname), _language(language) {}

    std::string getLogin() const { return _login; }
    std::string getPassword() const { return _password; }
    std::string getNickname() const { return _nickname; }
    std::string getLanguage() const { return _language; }

    void setLogin(const std::string& login) { _login = login; }
    void setPassword(const std::string& password) { _password = password; }
    void setNickname(const std::string& nickname) { _nickname = nickname; }
    void setLanguage(const std::string& language) { _language = language; }

    boost::json::value toJSON() const {
        return { {"login", _login}, {"password", _password}, {"nickname", _nickname}, {"language", _language} };
    }

private:
    std::string _login;
    std::string _password;
    std::string _nickname;
    std::string _language;
};
