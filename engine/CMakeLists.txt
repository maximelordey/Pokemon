cmake_minimum_required(VERSION 3.0.0)
project(engine VERSION 1.0.0)

add_library(engine)

target_include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(engine)
