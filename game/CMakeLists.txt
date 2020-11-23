cmake_minimum_required(VERSION 3.0.0)
project(Pokemon VERSION 1.0.0)

add_executable(Pokemon main.cpp
"${CMAKE_CURRENT_SOURCE_DIR}/include/utils/gauge.h" "${CMAKE_CURRENT_SOURCE_DIR}/src/utils/gauge.cpp"
)

target_include_directories(Engine PUBLIC 
"${CMAKE_CURRENT_SOURCE_DIR}/include/utils"
)

target_link_libraries(Pokemon LINK_PUBLIC Engine)

install(TARGETS Pokemon DESTINATION bin)
