cmake_minimum_required(VERSION 3.10)
project(SumRanks)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -lpthread")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Operations REQUIRED IntegerOperations)
find_package(Utilities REQUIRED CoutExtended)

add_executable(SumRanks ./main.cpp)
target_link_libraries(SumRanks PRIVATE Operations::IntegerOperations)
target_link_libraries(SumRanks PRIVATE Utilities::CoutExtended)
