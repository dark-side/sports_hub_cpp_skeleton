#ifndef TOKENGENERATOR_H
#define TOKENGENERATOR_H

#include <string>
#include <jwt-cpp/jwt.h>

class JwtToken {
public:
    JwtToken();
    std::string generateToken(const std::string& userID);

private:
    jwt::decoded_jwt<jwt::traits::kazuho_picojson> validateToken(const std::string& token);

    std::string _secretKey;
    std::string _issuer;
};

#endif //TOKENGENERATOR_H
