cmake_minimum_required(VERSION 3.16)
project(MiniOS)

set(CMAKE_CXX_STANDARD_REQUIRED 11)

add_library(functions src/functions/functions.cpp)
target_include_directories(functions PUBLIC ./include)

add_executable(minios src/main.cpp)

target_link_libraries(minios PRIVATE functions)
