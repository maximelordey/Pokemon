cmake_minimum_required(VERSION 3.0.0)
project(monster VERSION 1.0.0)

add_library(monster)

target_include_directories(monster PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")

target_sources(monster PUBLIC
"${CMAKE_CURRENT_SOURCE_DIR}/include/iv.h"
)

target_sources(monster PRIVATE
"${CMAKE_CURRENT_SOURCE_DIR}/src/iv.cpp"
)

target_link_libraries(monster PUBLIC common)
