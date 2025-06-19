#ifndef BASESERVICE_H
#define BASESERVICE_H

#include <App.h>
#include <memory>

class BaseService {
public:
    void start();
    void stop();

private:
    std::unique_ptr<uWS::App> app;
};

#endif // BASESERVICE_H
