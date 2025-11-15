cmake_minimum_required(VERSION 3.25)                         # минимальная версия cmake
project(polimorphism)                                        # название проекта

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -lpthread -save-temps")   # флаги компиляции

# add_library(addition SHARED addition.cpp)                    # создание динамической библиотеки

add_executable(additionProg main.cpp)           # создание исполняемого файла проекта
# target_link_libraries(additionProg addition)                 # линковка библиотек для исполняемого файла

