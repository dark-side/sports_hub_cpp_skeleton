#ifndef SIGNOUTHANDLER_H
#define SIGNOUTHANDLER_H

#include <Poco/Net/HTTPRequestHandler.h>

class SignOutHandler : public Poco::Net::HTTPRequestHandler {
public:
    void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response) override;
};



#endif //SIGNOUTHANDLER_H
