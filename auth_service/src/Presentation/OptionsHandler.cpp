#include "OptionsHandler.h"
#include <iostream>
#include <Poco/Net/HTTPServerResponse.h>

using namespace Poco::Net;

void OptionsHandler::handleRequest(HTTPServerRequest& request, HTTPServerResponse& response) {
    std::cout << "Handling OPTIONS request..." << std::endl;

    response.setStatus(HTTPResponse::HTTP_OK);
    response.setContentType("text/plain");
    response.set("Access-Control-Allow-Origin", "*");
    response.set("Access-Control-Allow-Methods", "GET, POST, OPTIONS, DELETE");
    response.set("Access-Control-Allow-Headers", "Content-Type, Authorization");

    response.send();
}
