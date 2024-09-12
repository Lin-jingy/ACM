cmake_minimum_required(VERSION 3.29)
project(ACM)
set (CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -O2 -ggdb -std=c++20 -Wall -Wno-deprecated -Werror -Wno-unused-function")

set(CMAKE_CXX_STANDARD 20)

add_executable(ACM 1.cpp)
