cmake_minimum_required(VERSION 3.10)

project(BaseServiceProject VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the library
add_library(BaseService STATIC
    src/BaseService.cpp
)

target_include_directories(BaseService PUBLIC include)

# Add the executable
add_executable(BaseServiceExecutable src/main.cpp)

target_link_libraries(BaseServiceExecutable PRIVATE BaseService)

# Add Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(BaseServiceTests tests/BaseServiceTests.cpp)
target_link_libraries(BaseServiceTests PRIVATE BaseService gtest gtest_main)
add_test(NAME BaseServiceTests COMMAND BaseServiceTests)

# Add uSockets
FetchContent_Declare(
  uSockets_content
  GIT_REPOSITORY https://github.com/uNetworking/uSockets
  GIT_TAG v0.8.8
  GIT_SHALLOW ON
  GIT_SUBMODULES ""
)
FetchContent_MakeAvailable(uSockets_content)

# Create uSockets library
file(GLOB_RECURSE SOURCES ${usockets_content_SOURCE_DIR}/src/*.c)
add_library(uSockets ${SOURCES})
include_directories(${usockets_content_SOURCE_DIR}/src/)
target_include_directories(uSockets PUBLIC ${usockets_content_SOURCE_DIR}/src)
target_compile_definitions(uSockets PRIVATE LIBUS_NO_SSL)

# Add uWebSockets
FetchContent_Declare(
  uWebSockets_content
  GIT_REPOSITORY https://github.com/uNetworking/uWebSockets
  GIT_TAG v20.74.0
  GIT_SHALLOW ON
  GIT_SUBMODULES ""
)
FetchContent_MakeAvailable(uWebSockets_content)

# Create uWebSockets library
find_package(ZLIB REQUIRED)
add_library(uWebSockets INTERFACE)
include_directories(${uwebsockets_content_SOURCE_DIR}/src/)
target_include_directories(uWebSockets INTERFACE ${uwebsockets_content_SOURCE_DIR}/src/)
target_link_libraries(uWebSockets INTERFACE uSockets ${ZLIB_LIBRARIES})
#target_compile_options(uWebSockets INTERFACE -Wno-deprecated-declarations)

# Link uWebSockets to the BaseService
target_link_libraries(BaseService PRIVATE uSockets uWebSockets)
