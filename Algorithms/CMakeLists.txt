cmake_minimum_required(VERSION 3.22)
project(Algorithms)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -lpthread")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)

add_library(Human SHARED ./src/Human.cpp)

add_executable(Algorithms ./main.cpp)
target_link_libraries(Algorithms Human)
