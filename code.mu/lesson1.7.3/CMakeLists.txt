cmake_minimum_required(VERSION 3.10)
project(lesson1.7.3)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -lpthread")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Operations REQUIRED)

add_executable(lesson1.7.3 ./main.cpp)
target_link_libraries(lesson1.7.3 PRIVATE Operations::IntegerOperations)
