cmake_minimum_required(VERSION 3.0.0)
project(move VERSION 1.0.0)

add_library(move)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/effect/")

target_include_directories(move PUBLIC 
"${CMAKE_CURRENT_SOURCE_DIR}/include"
common
monster
effect
)

target_link_libraries(move PRIVATE common monster effect)

target_sources(move PUBLIC
"${CMAKE_CURRENT_SOURCE_DIR}/include/move_accuracy.h"
"${CMAKE_CURRENT_SOURCE_DIR}/include/move_class.h"
"${CMAKE_CURRENT_SOURCE_DIR}/include/move.h"
"${CMAKE_CURRENT_SOURCE_DIR}/include/move_power.h"
"${CMAKE_CURRENT_SOURCE_DIR}/include/move_power_point.h"
)

target_sources(move PRIVATE)
