#include "UsersHandler.h"
#include <Poco/Net/HTTPServerResponse.h>

using namespace Poco::Net;

void UsersHandler::handleRequest(HTTPServerRequest& request, HTTPServerResponse& response) {
    response.setStatus(HTTPResponse::HTTP_OK);
    response.setContentType("text/plain");

    std::cout << " Users Handler ... " << std::endl;
    std::ostream& out = response.send();
    out << "Users Handler!";
}
