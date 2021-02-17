cmake_minimum_required(VERSION 3.0.0)
project(Pokemon VERSION 1.0.0)

add_executable(Pokemon main.cpp)

target_include_directories(Pokemon PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/utils/")

target_sources(Pokemon PUBLIC
"${CMAKE_CURRENT_SOURCE_DIR}/include/utils/gauge.h"
)

target_sources(Pokemon PRIVATE
"${CMAKE_CURRENT_SOURCE_DIR}/src/utils/gauge.cpp"
)
