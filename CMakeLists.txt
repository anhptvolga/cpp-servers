cmake_minimum_required(VERSION 3.13)
project(cpp_servers)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(third-party/drogon)
add_subdirectory(third-party/spdlog)

add_subdirectory(src/drogon-sv)
add_subdirectory(src/mongodb-test)
