cmake_minimum_required(VERSION 3.0.0)
project(engine VERSION 1.0.0)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/module/visual_module)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/module/sound_module)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/module/input_module)

add_library(engine INTERFACE)

target_link_libraries(engine INTERFACE visual_module sound_module input_module)
