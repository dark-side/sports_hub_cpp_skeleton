#include "BaseService.h"
#include <gtest/gtest.h>
#include <string>
#include <httplib.h>

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

    httplib::Client client("http://localhost:9001");

    auto res = client.Get("/greet");
    ASSERT_NE(res, nullptr);
    EXPECT_EQ(res->status, 200);
    EXPECT_EQ(res->body, "Hello, World!");

    service.stop();
}
