cmake_minimum_required(VERSION 3.10)
project(WhileClause)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -lpthread")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include/)

add_library(Zadanie1 SHARED ./src/Zadanie1.cpp)
add_library(Zadanie2 SHARED ./src/Zadanie2.cpp)

add_executable(WhileClause ./main.cpp)
target_link_libraries(WhileClause PRIVATE Zadanie1 Zadanie2)

install(TARGETS
    Zadanie1
    Zadanie2
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib/WhileClause
    ARCHIVE DESTINATION lib/WhileClause
)

install(FILES
  include/Zadanie1.h
  include/Zadanie2.h
    DESTINATION include/while_clause
)
