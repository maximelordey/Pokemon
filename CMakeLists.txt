cmake_minimum_required(VERSION 3.0.0)
project(Pokemon VERSION 1.0.0)

add_subdirectory(engine)
add_subdirectory(game)

add_executable(Pokemon main.cpp)