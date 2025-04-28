#ifndef USERSHANDLER_H
#define USERSHANDLER_H

#include <Poco/Net/HTTPRequestHandler.h>

class UsersHandler : public Poco::Net::HTTPRequestHandler {
public:
    void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response) override;
};

#endif //USERSHANDLER_H
