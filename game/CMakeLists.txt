cmake_minimum_required(VERSION 3.0.0)
project(game VERSION 1.0.0)

add_executable(game main.cpp)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/main/common")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/main/monster")

target_link_libraries(game PUBLIC common monster)