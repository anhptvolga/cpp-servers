cmake_minimum_required(VERSION 2.8)
#project(thread-safe-lru)

add_executable(benchmark1 benchmark.cpp)

include(FindTBB.cmake)

# Put this cmake file in a directory, run "cmake ."  finding TBB results in a FATAL_ERROR from cmake
find_package(TBB REQUIRED CONFIG)
#if(NOT TBB_FOUND)
#    message(FATAL_ERROR "NO TBB")
#else()
#    message(STATUS "FOUND TBB")
#endif()

include(FindPkgConfig)
pkg_search_module(TBB REQUIRED tbb)
target_link_libraries(benchmark1 ${TBB_LIBRARIES})
include_directories(${TBB_INCLUDE_DIRS})

# Boost is needed for the benchmark only
include(FindBoost)
find_package(Boost REQUIRED COMPONENTS locale)
target_link_libraries(benchmark1 ${Boost_LIBRARIES})
include_directories(${Boost_INCLUDE_DIRS})

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_CXX_FLAGS "-std=c++11 -O3")
