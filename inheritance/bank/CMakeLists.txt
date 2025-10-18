cmake_minimum_required(VERSION 3.22)
project(bank)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -lpthread")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(Credit INTERFACE)
target_include_directories(Credit INTERFACE ./abstracts)

add_library(Factoring INTERFACE)
target_include_directories(Factoring INTERFACE ./impl)
target_link_libraries(Factoring INTERFACE Credit)

add_library(ConsumerCredit INTERFACE)
target_include_directories(ConsumerCredit INTERFACE ./impl)
target_link_libraries(ConsumerCredit INTERFACE Credit)

add_executable(bank ./main.cpp)
target_link_libraries(bank PRIVATE ConsumerCredit Factoring Credit)
