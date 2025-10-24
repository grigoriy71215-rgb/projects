cmake_minimum_required(VERSION 3.22)
project(homeWork)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -lpthread")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)

add_library(Monster SHARED ./src/monster.cpp)

add_library(Human SHARED ./src/human.cpp)
target_link_libraries(Human PRIVATE Monster)

add_executable(homeWork ./main.cpp)
target_link_libraries(homeWork PRIVATE Human Monster)
