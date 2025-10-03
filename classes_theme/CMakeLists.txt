cmake_minimum_required(VERSION 3.22)
project(ClassTheme)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -lpthread")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(MyClass SHARED ./src/MyClass.cpp)

add_executable(ClassTheme ./main.cpp ./src/MyClass.cpp)
target_link_libraries(ClassTheme MyClass)
