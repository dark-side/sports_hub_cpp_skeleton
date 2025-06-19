#include "BaseService.h"
#include <iostream>

void BaseService::start() {
    app = std::make_unique<uWS::App>();

    app->get("/greet", [](auto *res, auto *req) {
        std::cout << "Handling /greet request" << std::endl;
        res->end("Hello, World!");
    });

    std::cout << "BaseService started." << std::endl;
    app->listen(9001, [](auto *token) {
        if (token) {
            std::cout << "Server listening on port 9001" << std::endl;
        } else {
            std::cout << "Failed to listen on port 9001" << std::endl;
        }
    });

    app->run();
}

void BaseService::stop() {
    std::cout << "BaseService stopped." << std::endl;
}
