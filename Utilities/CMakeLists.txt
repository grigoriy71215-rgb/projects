cmake_minimum_required(VERSION 3.22)
project(Utilities VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

include_directories(
  ./include/
)

add_library(CinFeatures SHARED ./src/system/CinFeatures.cpp)
add_library(SafeInput SHARED ./src/system/SafeInput.cpp)
add_library(CoutExtended SHARED ./src/system/CoutExtended.cpp)
add_library(LocalDate SHARED ./src/types/LocalDate.cpp)

install(TARGETS
    CinFeatures
    CoutExtended
    SafeInput
    LocalDate
    EXPORT TaskTrackerTargets
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib/utilities
    ARCHIVE DESTINATION lib/utilities
)

install(FILES
    include/system/CinFeatures.h
    include/system/SafeInput.h
    include/system/CoutExtended.h
    DESTINATION include/utilities/system
)

install(FILES
    include/types/LocalDate.h
    DESTINATION include/utilities/types
)

# Подключаем необходимые модули
include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

# Создаем и устанавливаем файлы конфигурации пакета
install(EXPORT TaskTrackerTargets
    FILE UtilitiesTargets.cmake
    NAMESPACE Utilities::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Utilities
)

write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/UtilitiesConfigVersion.cmake"
    VERSION "${PROJECT_VERSION}"
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(
    "${CMAKE_SOURCE_DIR}/cmake/UtilitiesConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/UtilitiesConfig.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Utilities
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/UtilitiesConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/UtilitiesConfigVersion.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Utilities
)
