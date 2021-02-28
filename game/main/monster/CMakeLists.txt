cmake_minimum_required(VERSION 3.0.0)
project(monster VERSION 1.0.0)

add_library(monster)

target_include_directories(monster PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")

target_sources(monster PUBLIC
"${CMAKE_CURRENT_SOURCE_DIR}/include/coefficient.h"
"${CMAKE_CURRENT_SOURCE_DIR}/include/ev.h"
"${CMAKE_CURRENT_SOURCE_DIR}/include/height.h"
"${CMAKE_CURRENT_SOURCE_DIR}/include/iv.h"
"${CMAKE_CURRENT_SOURCE_DIR}/include/nature.h"
"${CMAKE_CURRENT_SOURCE_DIR}/include/pokemon.h"
"${CMAKE_CURRENT_SOURCE_DIR}/include/specie_create_info.h"
"${CMAKE_CURRENT_SOURCE_DIR}/include/specie.h"
"${CMAKE_CURRENT_SOURCE_DIR}/include/stats.h"
"${CMAKE_CURRENT_SOURCE_DIR}/include/type.h"
"${CMAKE_CURRENT_SOURCE_DIR}/include/weight.h"
)

target_sources(monster PRIVATE
"${CMAKE_CURRENT_SOURCE_DIR}/src/coefficient.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/ev.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/nature.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/pokemon.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/specie.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/type.cpp"
)

target_link_libraries(monster PUBLIC common experience)
