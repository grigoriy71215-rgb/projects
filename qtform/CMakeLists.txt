cmake_minimum_required(VERSION 3.16)

project(QtForm VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -lpthread")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

# *** СНАЧАЛА ОПРЕДЕЛЯЕМ ИСПОЛНЯЕМЫЙ ФАЙЛ ***
add_executable(QtForm
    main.cpp
    src/MainWindow.cpp
    include/MainWindow.h
)

# *** ТОЛЬКО ПОТОМ УКАЗЫВАЕМ ПАПКИ INCLUDE И ЛИНКОВКУ ***

# Используем target_include_directories (это современный подход)
target_include_directories(QtForm PRIVATE include)

target_link_libraries(QtForm PRIVATE Qt6::Widgets)

