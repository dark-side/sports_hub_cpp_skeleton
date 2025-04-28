#include "AuthServiceApp.h"
#include "../Presentation/AuthHandlerFactory.h"
#include <Poco/Net/HTTPServer.h>

using namespace Poco::Util;
using namespace Poco::Net;

int AuthServiceApp::main(const std::vector<std::string>&) {

    // Load default configuration
    loadConfiguration(); // Loads the default configuration file (config.properties)

    // Read IP and port from the configuration
    std::string ip = config().getString("server.ip", "127.0.0.1"); // Default to 127.0.0.1
    int port = config().getInt("server.port", 8080); // Default to 8080

    // Create and start the HTTP server
    HTTPServer server(new AuthHandlerFactory(), ServerSocket(SocketAddress(ip, port)), new HTTPServerParams);
    server.start();

    std::cout << "Auth Service running on http://" << ip << ":" << port << std::endl;
    waitForTerminationRequest();
    server.stop();

    return Application::EXIT_OK;
}