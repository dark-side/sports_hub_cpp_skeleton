#include <Poco/Net/HTTPServer.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Util/ServerApplication.h>
#include <iostream>

using namespace Poco::Net;
using namespace Poco::Util;

class HelloHandler : public HTTPRequestHandler {
public:
    void handleRequest(HTTPServerRequest& request, HTTPServerResponse& response) override {
        response.setStatus(HTTPResponse::HTTP_OK);
        response.setContentType("text/plain");
        std::ostream& out = response.send();
        out << "Hello from C++ Backend Service (HTTP)!";
    }
};

class HelloHandlerFactory : public HTTPRequestHandlerFactory {
public:
    HTTPRequestHandler* createRequestHandler(const HTTPServerRequest&) override {
        return new HelloHandler;
    }
};

class BackendServiceApp : public ServerApplication {
protected:
    int main(const std::vector<std::string>&) override {
        HTTPServer server(new HelloHandlerFactory(), ServerSocket(8080), new HTTPServerParams);
        server.start();
        std::cout << "Backend Service running on http://localhost:8080" << std::endl;
        waitForTerminationRequest();
        server.stop();
        return Application::EXIT_OK;
    }
};

int main(int argc, char** argv) {
    BackendServiceApp app;
    return app.run(argc, argv);
}
