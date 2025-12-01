cmake_minimum_required(VERSION 3.10)
project(ForwardDeclaration)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -lpthread")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)

add_library(A SHARED ./src/A.cpp)

add_executable(ForwardDeclaration ./main.cpp)
target_link_libraries(ForwardDeclaration PRIVATE A)
