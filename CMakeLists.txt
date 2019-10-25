cmake_minimum_required(VERSION 3.14)
project(cpp_servers)

set(CMAKE_CXX_STANDARD 17)


#include(cmake-modules/drogon.cmake)
#include(cmake-modules/spdlog.cmake)

find_package(spdlog REQUIRED)
add_subdirectory(third-party/drogon)

add_subdirectory(src/drogon-sv)
