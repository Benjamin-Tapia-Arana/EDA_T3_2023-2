cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_COMPILER "/usr/bin/g++")
# set the project name

project(laberinto
VERSION 1.0
LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#add_subdirectory(src)
#add_subdirectory(tests)

add_executable(calculator test/test.cpp src/interactiveIO.cpp src/calculator.cpp src/utils.cpp src/tree.cpp src/stack.cpp src/node.cpp)
target_include_directories(calculator PUBLIC ${PROJECT_SOURCE_DIR}/include)


# add the executable