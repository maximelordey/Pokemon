cmake_minimum_required(VERSION 3.0.0)
project(game VERSION 1.0.0)

add_library(game)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/main/model/common")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/main/model/experience")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/main/model/monster")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/main/model/specie")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/main/model/move")

target_include_directories(game PUBLIC common monster move engine)

target_link_libraries(game PRIVATE common monster move engine)
