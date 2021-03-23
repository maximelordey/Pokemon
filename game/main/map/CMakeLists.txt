cmake_minimum_required(VERSION 3.0.0)
project(map VERSION 1.0.0)

add_library(map)

target_include_directories(map PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")

target_sources(map PUBLIC
"${CMAKE_CURRENT_SOURCE_DIR}/include/map.h"
"${CMAKE_CURRENT_SOURCE_DIR}/include/tile_type.h"
"${CMAKE_CURRENT_SOURCE_DIR}/include/tile.h"
)
