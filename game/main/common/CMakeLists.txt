cmake_minimum_required(VERSION 3.0.0)
project(common VERSION 1.0.0)


add_library(common)

target_include_directories(common PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")

target_sources(common PUBLIC
"${CMAKE_CURRENT_SOURCE_DIR}/include/gauge.h"
"${CMAKE_CURRENT_SOURCE_DIR}/include/language.h"
"${CMAKE_CURRENT_SOURCE_DIR}/include/text.h"
)

target_sources(common PRIVATE
"${CMAKE_CURRENT_SOURCE_DIR}/src/gauge.cpp"
)
