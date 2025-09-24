#include "AuthServiceApp.h"
#include <Presentation/AuthHandlerFactory.h>
#include <Poco/Net/HTTPServer.h>
#include <iostream>

using namespace Poco::Util;
using namespace Poco::Net;

int AuthServiceApp::main(const std::vector<std::string>&) {
    loadConfiguration("config/config.properties", PRIO_APPLICATION);

    std::string ip = config().getString("server.ip", "0.0.0.0");
    int port = config().getInt("server.port", 8080);

    HTTPServer server(new AuthHandlerFactory(), ServerSocket(SocketAddress(ip, port)),
                      new HTTPServerParams);
    server.start();

    std::cout << "Auth Service running on http://" << ip << ":" << port << std::endl;
    waitForTerminationRequest();
    server.stop();

    return Application::EXIT_OK;
}
