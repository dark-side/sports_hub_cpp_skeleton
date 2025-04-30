#include "JwtToken.h"
#include <string>
#include <stdexcept>
#include <chrono>
#include <cstdlib>

JwtToken::JwtToken() : _issuer("ydhnwb") {
        const char* envSecret = std::getenv("JWT_SECRET");
        _secretKey = envSecret ? std::string(envSecret) : "ydhnwb";
    }

std::string JwtToken::generateToken(const std::string& userID) {
        auto token = jwt::create()
            .set_issuer(_issuer)
            .set_subject(userID)
            .set_issued_at(std::chrono::system_clock::now())
            .set_expires_at(std::chrono::system_clock::now() + std::chrono::hours(24 * 365)) // 1 year
            .sign(jwt::algorithm::hs256{_secretKey});
        return token;
}

jwt::decoded_jwt<jwt::traits::kazuho_picojson> JwtToken::validateToken(const std::string& token) {
        auto verifier = jwt::verify()
            .allow_algorithm(jwt::algorithm::hs256{_secretKey})
            .with_issuer(_issuer);

        auto decoded = jwt::decode(token);
        verifier.verify(decoded);
        return decoded;
}
