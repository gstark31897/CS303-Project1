cmake_minimum_required(VERSION 2.8)
project(Project1)

set(SOURCE_FILES src/main.cpp src/term.cpp)
set(CMAKE_CXX_FLAGS "-g")

add_executable(Project1 ${SOURCE_FILES})

INCLUDE_DIRECTORIES("include/")
