#ifndef AUTH_H
#define AUTH_H

#include <Models/User.h>
#include <string>

class Auth {
public:
    std::string signIn(const User& user);
};



#endif //AUTH_H
