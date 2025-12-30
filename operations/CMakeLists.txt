cmake_minimum_required(VERSION 3.10)
project(Operations)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -lpthread")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Systemd unit file installation
set(SYSTEMD_UNIT_FILE "operations.service")
configure_file(
    "${CMAKE_SOURCE_DIR}/systemd/${SYSTEMD_UNIT_FILE}.in"
    "${CMAKE_BINARY_DIR}/${SYSTEMD_UNIT_FILE}"
    @ONLY
)

include_directories(include)

add_library(CharOperations SHARED ./src/CharOperations.cpp)
add_library(IntegerOperations SHARED ./src/IntegerOperations.cpp)
add_library(StringOperations SHARED ./src/StringOperations.cpp)

# 1. Сначала экспортируем цели
install(TARGETS
    CharOperations
    IntegerOperations
    StringOperations
    EXPORT OperationsTargets
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib/operations
    ARCHIVE DESTINATION lib/operations
)

# 2. Установка заголовочных файлов
install(FILES
    include/CharOperations.h
    include/IntegerOperations.h
    include/StringOperations.h
    DESTINATION include/operations
)

# 3. Установка экспортированных целей
install(EXPORT OperationsTargets
    FILE OperationsTargets.cmake
    NAMESPACE Operations::
    DESTINATION lib/cmake/Operations
)

# 4. Генерация и установка файла конфигурации пакета
include(CMakePackageConfigHelpers)

# Создаём файл конфигурации пакета
configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/OperationsConfig.cmake"
    INSTALL_DESTINATION lib/cmake/Operations
)

# Устанавливаем сгенерированный файл конфигурации
install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/OperationsConfig.cmake"
    DESTINATION lib/cmake/Operations
)

# 5. Установка systemd файла
install(FILES "${CMAKE_BINARY_DIR}/${SYSTEMD_UNIT_FILE}"
    DESTINATION lib/systemd/system
    PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
)
