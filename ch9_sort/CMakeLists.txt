cmake_minimum_required(VERSION 2.8)
project(sort_algorithm)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "-std=c++11")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(sort_algorithm src/main.cpp src/SortAlgorithm.cpp)