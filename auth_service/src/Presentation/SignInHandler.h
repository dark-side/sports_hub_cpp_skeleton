#ifndef SIGNINHANDLER_H
#define SIGNINHANDLER_H

#include <Poco/Net/HTTPRequestHandler.h>

class SignInHandler : public Poco::Net::HTTPRequestHandler {
public:
    void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response) override;
};



#endif //SIGNINHANDLER_H
