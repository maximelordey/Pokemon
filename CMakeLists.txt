cmake_minimum_required(VERSION 3.0.0)
project(pokemon)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(engine)
add_subdirectory(game)

add_executable(pokemon main.cpp)

target_include_directories(pokemon PUBLIC engine game)

target_link_libraries(pokemon PRIVATE engine game)
