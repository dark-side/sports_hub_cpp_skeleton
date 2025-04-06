cmake_minimum_required(VERSION 3.10)
project(auth_service)

set(CMAKE_CXX_STANDARD 20)

find_package(Poco REQUIRED COMPONENTS Net Util)

add_executable(auth_service src/cpp_auth_service.cpp)
target_link_libraries(auth_service PRIVATE Poco::Net Poco::Util)
