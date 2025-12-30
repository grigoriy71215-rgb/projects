cmake_minimum_required(VERSION 3.10)
project(Lesson1.9.5)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -lpthread")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Operations REQUIRED CharOperations)

add_executable(prog main.cpp)
target_link_libraries(prog PRIVATE Operations::CharOperations)
