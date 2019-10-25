cmake_minimum_required(VERSION 3.13)
project(cpp_servers)

set(CMAKE_CXX_STANDARD 17)


#include(cmake-modules/drogon.cmake)
#include(cmake-modules/spdlog.cmake)

#add_subdirectory(third-party/spdlog)
#find_package(spdlog REQUIRED)
add_subdirectory(third-party/drogon)
#find_package(drogon REQUIRED)


add_executable(cpp_servers src/main.cpp src/PlainText.h src/PlainText.cc src/demo_v1_User.h src/demo_v2_User.cc)
target_include_directories(cpp_servers PRIVATE drogon)
target_link_libraries(cpp_servers PRIVATE drogon)
#add_dependencies(cpp_servers spdlog drogon)
