cmake_minimum_required(VERSION 3.22)
project(bank)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -lpthread")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(Credit INTERFACE)
target_include_directories(Credit INTERFACE ./abstracts)

include_directories(
  abstracts
  impl
)

add_library(Factoring SHARED ./impl/Factoring.cpp)
target_link_libraries(Factoring PRIVATE Credit)

add_library(ConsumerCredit SHARED ./impl/ConsumerCredit.cpp)
target_link_libraries(ConsumerCredit PRIVATE Credit)

add_executable(bank ./main.cpp)
target_link_libraries(bank PRIVATE ConsumerCredit Factoring Credit)
