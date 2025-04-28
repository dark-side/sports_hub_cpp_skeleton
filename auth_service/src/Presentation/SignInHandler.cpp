#include "SignInHandler.h"
#include <Poco/Net/HTTPServerResponse.h>

using namespace Poco::Net;

void SignInHandler::handleRequest(HTTPServerRequest& request, HTTPServerResponse& response) {
    response.setStatus(HTTPResponse::HTTP_OK);
    response.setContentType("text/plain");

    std::cout << " Sign In Handler ... " << std::endl;
    std::ostream& out = response.send();
    out << "Sign In Handler!";
}
