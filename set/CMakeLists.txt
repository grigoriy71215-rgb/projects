cmake_minimum_required(VERSION 3.10)
project(Set)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -lpthread")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)

add_library(Set SHARED ./src/Set.cpp)

add_executable(SetExecutable ./main.cpp)
target_link_libraries(SetExecutable PRIVATE Set)

