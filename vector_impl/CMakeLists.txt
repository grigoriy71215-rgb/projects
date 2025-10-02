cmake_minimum_required(VERSION 3.25)
project(vector)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -lpthread")

add_library(vector SHARED vector.cpp)

add_executable(vectorProg main.cpp vector.cpp)
target_link_libraries(vectorProg vector)

