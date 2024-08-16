cmake_minimum_required(VERSION 3.29)
project(poly)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(src)
add_executable(poly)
add_subdirectory(src)
