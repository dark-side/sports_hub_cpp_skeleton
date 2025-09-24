cmake_minimum_required(VERSION 3.10)
project(backend_service)

set(CMAKE_CXX_STANDARD 20)

find_package(Poco REQUIRED COMPONENTS Net Util)

add_executable(backend_service src/cpp_backend_service.cpp)
target_link_libraries(backend_service PRIVATE Poco::Net Poco::Util)
