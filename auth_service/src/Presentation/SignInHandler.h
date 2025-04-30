#ifndef SIGNINHANDLER_H
#define SIGNINHANDLER_H

#include <Poco/Net/HTTPRequestHandler.h>
#include <Models/User.h>

class SignInHandler : public Poco::Net::HTTPRequestHandler {
public:
    void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response) override;

private:
    static User parseRequestBody(const std::string& requestBody);

    static void sendResponse(Poco::Net::HTTPServerResponse& response, const std::string& jwt);
};

#endif //SIGNINHANDLER_H
