cmake_minimum_required(VERSION 3.0.0)
project(monster VERSION 1.0.0)

add_library(monster)

target_include_directories(monster PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/" common)

target_sources(monster PUBLIC
${CMAKE_CURRENT_SOURCE_DIR}/include/ev.h
${CMAKE_CURRENT_SOURCE_DIR}/include/experience.h
${CMAKE_CURRENT_SOURCE_DIR}/include/health.h
${CMAKE_CURRENT_SOURCE_DIR}/include/iv.h
${CMAKE_CURRENT_SOURCE_DIR}/include/level.hpp
${CMAKE_CURRENT_SOURCE_DIR}/include/pokemon.h
)

target_sources(monster PRIVATE
${CMAKE_CURRENT_SOURCE_DIR}/src/level.cpp
)

target_link_libraries(monster PUBLIC common experience specie)
