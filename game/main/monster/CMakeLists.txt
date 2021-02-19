cmake_minimum_required(VERSION 3.0.0)
project(monster VERSION 1.0.0)

add_library(monster)

target_include_directories(monster PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")

target_sources(monster PUBLIC
"${CMAKE_CURRENT_SOURCE_DIR}/include/iv.h"
"${CMAKE_CURRENT_SOURCE_DIR}/include/ev.h"
"${CMAKE_CURRENT_SOURCE_DIR}/include/specie.h"
"${CMAKE_CURRENT_SOURCE_DIR}/include/pokemon.h"
"${CMAKE_CURRENT_SOURCE_DIR}/include/type.h"
)

target_sources(monster PRIVATE
"${CMAKE_CURRENT_SOURCE_DIR}/src/iv.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/ev.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/specie.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/pokemon.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/type.cpp"
)

target_link_libraries(monster PUBLIC common experience)
