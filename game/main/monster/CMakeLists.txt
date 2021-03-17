cmake_minimum_required(VERSION 3.0.0)
project(monster VERSION 1.0.0)

add_library(monster)

target_include_directories(monster PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/" common)

target_sources(monster PUBLIC
"${CMAKE_CURRENT_SOURCE_DIR}/include/coefficient.h"
"${CMAKE_CURRENT_SOURCE_DIR}/include/ev.h"
"${CMAKE_CURRENT_SOURCE_DIR}/include/experience.h"
"${CMAKE_CURRENT_SOURCE_DIR}/include/health.h"
"${CMAKE_CURRENT_SOURCE_DIR}/include/height.h"
"${CMAKE_CURRENT_SOURCE_DIR}/include/iv.h"
"${CMAKE_CURRENT_SOURCE_DIR}/include/level.h"
"${CMAKE_CURRENT_SOURCE_DIR}/include/nature.h"
"${CMAKE_CURRENT_SOURCE_DIR}/include/pokemon.h"
"${CMAKE_CURRENT_SOURCE_DIR}/include/specie.h"
"${CMAKE_CURRENT_SOURCE_DIR}/include/stats.h"
"${CMAKE_CURRENT_SOURCE_DIR}/include/type.h"
"${CMAKE_CURRENT_SOURCE_DIR}/include/weaknesses.h"
"${CMAKE_CURRENT_SOURCE_DIR}/include/weight.h"
)

target_link_libraries(monster PUBLIC common experience)
