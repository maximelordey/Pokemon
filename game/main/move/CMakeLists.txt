cmake_minimum_required(VERSION 3.0.0)
project(move VERSION 1.0.0)

add_library(move)

target_include_directories(move PUBLIC 
"${CMAKE_CURRENT_SOURCE_DIR}/include/"
common
monster
)

target_link_libraries(move PRIVATE common monster)

target_sources(move PUBLIC
"${CMAKE_CURRENT_SOURCE_DIR}/include/move_class.h"
"${CMAKE_CURRENT_SOURCE_DIR}/include/move_create_info.h"
"${CMAKE_CURRENT_SOURCE_DIR}/include/move.h"
)

target_sources(move PRIVATE
"${CMAKE_CURRENT_SOURCE_DIR}/src/move.cpp"
)
