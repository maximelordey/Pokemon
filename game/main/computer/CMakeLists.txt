cmake_minimum_required(VERSION 3.0.0)
project(computer VERSION 1.0.0)

add_library(computer)

target_include_directories(computer PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/" monster)

target_sources(computer PUBLIC
"${CMAKE_CURRENT_SOURCE_DIR}/include/box.h"
"${CMAKE_CURRENT_SOURCE_DIR}/include/computer.h"
)

target_sources(computer PRIVATE
"${CMAKE_CURRENT_SOURCE_DIR}/src/computer.cpp"
)

target_link_libraries(computer PRIVATE monster)