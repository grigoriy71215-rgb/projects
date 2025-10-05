cmake_minimum_required(VERSION 3.22)
project(StringOperationsProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -lpthread")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(OccuranciesGetter SHARED ./src/OccuranciesGetter.cpp)

add_executable(StringOperationsProject ./main.cpp ./src/OccuranciesGetter.cpp)
target_link_libraries(StringOperationsProject OccuranciesGetter)

install(TARGETS
    OccuranciesGetter
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib/string-operations
    ARCHIVE DESTINATION lib/string-operations
)

install(FILES
    include/OccuranciesGetter.h
    DESTINATION include/string-operations
)
