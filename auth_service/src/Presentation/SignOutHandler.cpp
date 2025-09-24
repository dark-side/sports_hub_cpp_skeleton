#include "SignOutHandler.h"
#include <Poco/Net/HTTPServerResponse.h>
#include <iostream>

using namespace Poco::Net;

void SignOutHandler::handleRequest(HTTPServerRequest& request, HTTPServerResponse& response) {
    response.setStatus(HTTPResponse::HTTP_OK);
    response.setContentType("text/plain");

    std::cout << " Sign Out Handler ... " << std::endl;
    std::ostream& out = response.send();
    out << "Sign Out Handler!";
}
