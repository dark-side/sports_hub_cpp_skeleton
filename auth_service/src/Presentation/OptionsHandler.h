#ifndef OPTIONSHANDLER_H
#define OPTIONSHANDLER_H

#include <Poco/Net/HTTPRequestHandler.h>

class OptionsHandler : public Poco::Net::HTTPRequestHandler {
public:
    void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response) override;
};

#endif //OPTIONSHANDLER_H
