#ifndef HANDLERFACTORY_H
#define HANDLERFACTORY_H

#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/HTTPServerRequest.h>

class AuthHandlerFactory : public Poco::Net::HTTPRequestHandlerFactory {
public:
    Poco::Net::HTTPRequestHandler* createRequestHandler(const Poco::Net::HTTPServerRequest&) override;
};

#endif //HANDLERFACTORY_H
