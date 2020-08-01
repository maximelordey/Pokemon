cmake_minimum_required(VERSION 3.0.0)
project(Pokemon VERSION 1.0.0)

add_subdirectory(engine)
add_subdirectory(game)

message( STATUS "CMAKE_BUILD_TYPE: " ${CMAKE_BUILD_TYPE})
message( STATUS "CMAKE_CXX_FLAGS: " ${CMAKE_CXX_FLAGS})
message( STATUS "CMAKE_CXX_STANDARD: " ${CMAKE_CXX_STANDARD})

include(CTest)
enable_testing()

add_executable(Pokemon main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
