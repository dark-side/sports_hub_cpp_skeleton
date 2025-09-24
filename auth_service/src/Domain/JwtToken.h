#ifndef TOKENGENERATOR_H
#define TOKENGENERATOR_H

#include <string>

class JwtToken {
public:
    JwtToken();
    std::string generateToken(const std::string& userID);

private:
    std::string _secretKey;
    std::string _issuer;
};

#endif //TOKENGENERATOR_H
