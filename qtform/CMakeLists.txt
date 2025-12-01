cmake_minimum_required(VERSION 3.16)

project(QtForm VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -lpthread")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

include_directories(include)

add_library(OurLabel SHARED ./src/OurLabel.cpp ./include/OurLabel.h)
target_link_libraries(OurLabel PRIVATE Qt6::Widgets)

add_executable(QtForm
    main.cpp
    src/MainWindow.cpp
    include/MainWindow.h
)

target_include_directories(QtForm PRIVATE include)

target_link_libraries(QtForm PRIVATE Qt6::Widgets OurLabel)

