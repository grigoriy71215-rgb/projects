cmake_minimum_required(VERSION 3.10)
project(Lesson2.2.3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -lpthread")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Operations REQUIRED IntegerOperations)

add_executable(lesson2.2.3 main.cpp)
target_link_libraries(lesson2.2.3 Operations::IntegerOperations)
