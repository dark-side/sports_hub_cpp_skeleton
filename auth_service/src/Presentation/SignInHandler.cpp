#include "SignInHandler.h"
#include <Domain/JwtToken.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/JSON/Parser.h>
#include <Poco/JSON/Object.h>
#include <Poco/Dynamic/Var.h>
#include <iostream>
#include <string>

using namespace std;
using namespace Poco::Net;
using namespace Poco::JSON;
using namespace Poco::Dynamic;

User SignInHandler::parseRequestBody(const std::string& requestBody) {
    User user;
    Parser parser;
    Var result = parser.parse(requestBody);
    Object::Ptr jsonObject = result.extract<Object::Ptr>();
    Object::Ptr userObject = jsonObject->getObject("user");
    user.email = userObject->getValue<std::string>("email");
    user.password = userObject->getValue<std::string>("password");
    return user;
}

void SignInHandler::sendResponse(HTTPServerResponse& response, const string& jwt) {
    try {
        response.setStatus(HTTPResponse::HTTP_OK);
        response.setContentType("application/json");
        response.set("Access-Control-Allow-Origin", "*");
        response.set("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
        response.set("Access-Control-Allow-Headers", "Content-Type");
        std::ostream& out = response.send();
        std::cout << "Response Body: " << R"({"token":")" + jwt + R"("})" << std::endl;

        out << R"({"token":")" << jwt << R"("})";
    } catch (const std::exception& e) {
        std::cerr << "Error generating JWT: " << e.what() << std::endl;
        response.setStatus(HTTPResponse::HTTP_INTERNAL_SERVER_ERROR);
        response.send() << R"({"error":"Failed to generate token"})";
    };
}

void SignInHandler::handleRequest(HTTPServerRequest& request, HTTPServerResponse& response) {
    response.setContentType("application/json");

    // Read the request body
    std::istream& requestStream = request.stream();
    std::string requestBody((std::istreambuf_iterator<char>(requestStream)), std::istreambuf_iterator<char>());
    std::cout << "Request Body: " << requestBody << std::endl;

    User user;
    try {
        user = parseRequestBody(requestBody);
        std::cout << "Parsed User Email: " << user.email << std::endl;

        JwtToken jwtService;
        std::string jwt = jwtService.generateToken(user.email);

        sendResponse(response, jwt);
    } catch (const std::exception& e) {
        std::cerr << "Error parsing request body: " << e.what() << std::endl;
        response.setStatus(HTTPResponse::HTTP_BAD_REQUEST);
        response.send() << R"({"error":"Invalid JSON format"})";
    }
}
