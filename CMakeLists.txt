cmake_minimum_required(VERSION 3.0.0)
project(DijkstraHomework VERSION 0.1.0)

# Use CPP 11
set(CMAKE_CXX_STANDARD 11)
# Set leak detectation when using clang compiler 
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" AND CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS "-fsanitize=leak -g")
endif()

# Add the the third part header file
include_directories(include)

# Add cpp files to target
set(SRC_LIST src/main.cpp src/Graph.cpp src/util.cpp)
add_executable(DijkstraHomework ${SRC_LIST})