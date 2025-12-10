cmake_minimum_required(VERSION 3.10)
project(Float)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -lpthread")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)

add_library(Float SHARED ./src/Float.cpp)

add_executable(FloatExecutable ./main.cpp)
target_link_libraries(FloatExecutable PRIVATE Float)
