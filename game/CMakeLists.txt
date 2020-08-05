cmake_minimum_required(VERSION 3.0.0)
project(Pokemon VERSION 1.0.0)

add_executable(Pokemon main.cpp)
target_link_libraries(Pokemon LINK_PUBLIC Engine)

install(TARGETS Pokemon DESTINATION bin)