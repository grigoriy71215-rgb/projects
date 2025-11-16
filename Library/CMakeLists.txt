cmake_minimum_required(VERSION 3.22)
project(Libary)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -lpthread")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(Book SHARED ./src/Book.cpp)

add_library(TextBook SHARED ./src/TextBook.cpp)
target_link_libraries(TextBook PRIVATE Book)

add_library(FictionBook SHARED ./src/FictionBook.cpp)
target_link_libraries(FictionBook PRIVATE Book)

add_executable(Library ./main.cpp)
target_link_libraries(Library PRIVATE Book TextBook FictionBook)
