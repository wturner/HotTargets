cmake_minimum_required(VERSION 2.8)
project(HotTargets)

#setting command line flags for C++ 11
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
find_package(OpenCV REQUIRED)
add_executable(run run.cpp)
target_link_libraries( run ${OpenCV_LIBS} )
