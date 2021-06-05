cmake_minimum_required(VERSION 3.0.0)
project(experience VERSION 1.0.0)

add_library(experience)

target_include_directories(experience PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")

target_sources(experience PUBLIC
"${CMAKE_CURRENT_SOURCE_DIR}/include/iexperience_curve.hpp"
"${CMAKE_CURRENT_SOURCE_DIR}/include/fast_experience_curve.hpp"
"${CMAKE_CURRENT_SOURCE_DIR}/include/medium_fast_experience_curve.hpp"
"${CMAKE_CURRENT_SOURCE_DIR}/include/medium_slow_experience_curve.hpp"
"${CMAKE_CURRENT_SOURCE_DIR}/include/slow_experience_curve.hpp"
"${CMAKE_CURRENT_SOURCE_DIR}/include/fluctuating_experience_curve.hpp"
"${CMAKE_CURRENT_SOURCE_DIR}/include/erratic_experience_curve.hpp"
)

target_sources(experience PRIVATE
"${CMAKE_CURRENT_SOURCE_DIR}/src/fast_experience_curve.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/medium_fast_experience_curve.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/medium_slow_experience_curve.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/slow_experience_curve.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/fluctuating_experience_curve.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/erratic_experience_curve.cpp"
)