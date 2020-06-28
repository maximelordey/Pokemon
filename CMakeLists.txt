cmake_minimum_required(VERSION 3.0.0)
project(Pokemon VERSION 0.1.0)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

message( STATUS "CMAKE_BUILD_TYPE: " ${CMAKE_BUILD_TYPE})    
message( STATUS "CMAKE_CXX_FLAGS: " ${CMAKE_CXX_FLAGS})

include(CTest)
enable_testing()

add_executable(Pokemon main.cpp)
target_link_libraries(Pokemon ${SDL2_LIBRARIES})

target_include_directories(Pokemon PUBLIC
                        "${PROJECT_SOURCE_DIR}/include/engine/utils" 
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
