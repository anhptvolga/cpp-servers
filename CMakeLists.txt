cmake_minimum_required(VERSION 3.14)
project(cpp_servers)

set(CMAKE_CXX_STANDARD 17)


#include(cmake-modules/drogon.cmake)
#include(cmake-modules/spdlog.cmake)

add_subdirectory(third-party/drogon)
#add_subdirectory(third-party/spdlog)
#add_subdirectory(third-party/mongo)

add_subdirectory(src/drogon-sv)
add_subdirectory(src/mongodb-test)
