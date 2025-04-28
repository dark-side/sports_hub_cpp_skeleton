cmake_minimum_required(VERSION 3.10)
project(auth_service)

set(CMAKE_CXX_STANDARD 20)

find_package(Poco REQUIRED COMPONENTS Net Util)

file(GLOB SOURCES
        src/*.cpp
        src/Presentation/*.cpp
        src/Application/*.cpp
        src/Domain/*.cpp
        src/Infrastructure/*.cpp
)

file(GLOB HEADERS
        src/*.h
        src/Presentation/*.h
        src/Application/*.h
        src/Domain/*.h
        src/Infrastructure/*.h
)

add_executable(auth_service ${SOURCES} ${HEADERS})

target_link_libraries(auth_service PRIVATE
        Poco::Net
        Poco::Util)


option(BUILD_TESTS "Build tests" OFF)

if(BUILD_TESTS)
    enable_testing()
    find_package(GTest REQUIRED)

    file(GLOB TEST_SOURCES tests/*.cpp)

    add_executable(auth_service_tests ${TEST_SOURCES})

    target_link_libraries(auth_service_tests PRIVATE
            GTest::GTest
            GTest::Main
            Poco::Net
            Poco::Util
    )

    add_test(NAME TokenGeneratorTest COMMAND auth_service_tests)
endif()