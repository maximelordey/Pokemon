cmake_minimum_required(VERSION 3.0.0)
project(effect VERSION 1.0.0)

add_library(effect)

target_include_directories(effect PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" common)

target_link_libraries(effect PRIVATE common)

target_sources(effect PUBLIC
"${CMAKE_CURRENT_SOURCE_DIR}/include/effect.h"
)

target_sources(effect PRIVATE)
