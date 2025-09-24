#include "JwtToken.h"
#include <Poco/JWT/Signer.h>
#include <Poco/JWT/Token.h>
using namespace Poco::JWT;

JwtToken::JwtToken() : _issuer("ydhnwb") {
        const char* envSecret = std::getenv("JWT_SECRET");
        _secretKey = envSecret ? std::string(envSecret) : "ydhnwb";
    }

std::string JwtToken::generateToken(const std::string& userID) {
        Token token;
        token.setType("JWT");
        token.setSubject(userID);
        token.setIssuedAt(Poco::Timestamp());
        token.setExpiration(Poco::Timestamp() + Poco::Timespan(365, 0, 0, 0, 0)); // 1 year
        Signer signer(_secretKey);
        std::string jwt = signer.sign(token, Signer::ALGO_HS256);
        return jwt;
}
