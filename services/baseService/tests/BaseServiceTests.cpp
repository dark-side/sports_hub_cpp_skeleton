#include "BaseService.h"
#include <gtest/gtest.h>
#include <string>
#include <ClientApp.h>

TEST(BaseServiceTest, StartStopTest) {
    BaseService service;

    testing::internal::CaptureStdout();
    service.start();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "BaseService started.\nServer listening on port 9001\n");

    testing::internal::CaptureStdout();
    service.stop();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "BaseService stopped.\n");
}

TEST(BaseServiceApiTest, GreetEndpointTest) {
    BaseService service;
    service.start();

    uWS::ClientApp client({
        .open = []() {}, 
        .message = []() {},
        .close = []() {}});
    client.connect("http://localhost:9001/greet");
    client.run();

    service.stop();
}

