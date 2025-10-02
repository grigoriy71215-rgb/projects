qt5_add_resources(rdb_colors_SRCS resources.qrc)
add_executable(rdb_colors main.cpp ${rdb_colors_SRCS})
target_link_libraries(rdb_colors Qt5::Qml Qt5::Gui)

