cmake_minimum_required(VERSION 3.0.0)
project(specie VERSION 1.0.0)

add_library(specie)

target_include_directories(specie PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/" common)

target_sources(specie PUBLIC
"${CMAKE_CURRENT_SOURCE_DIR}/include/coefficient.h"
"${CMAKE_CURRENT_SOURCE_DIR}/include/height.h"
"${CMAKE_CURRENT_SOURCE_DIR}/include/nature.h"
"${CMAKE_CURRENT_SOURCE_DIR}/include/specie.h"
"${CMAKE_CURRENT_SOURCE_DIR}/include/stat.h"
"${CMAKE_CURRENT_SOURCE_DIR}/include/type.hpp"
"${CMAKE_CURRENT_SOURCE_DIR}/include/weight.h"
"${CMAKE_CURRENT_SOURCE_DIR}/include/effectiveness.hpp"
"${CMAKE_CURRENT_SOURCE_DIR}/include/effectiveness_comparator.hpp"
)

target_sources(specie PRIVATE
"${CMAKE_CURRENT_SOURCE_DIR}/src/effectiveness.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/effectiveness_comparator.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/type.cpp"
)

target_link_libraries(specie PUBLIC common experience)
