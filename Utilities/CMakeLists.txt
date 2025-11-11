cmake_minimum_required(VERSION 3.22)
project(Utilities VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -lpthread")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(
  ./include/
)

add_library(CinFeatures SHARED ./src/CinFeatures.cpp)

install(TARGETS
    CinFeatures
    EXPORT TaskTrackerTargets
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib/utilities
    ARCHIVE DESTINATION lib/utilities
)

install(FILES
  include/CinFeatures.h
    DESTINATION include/utilities/
)
