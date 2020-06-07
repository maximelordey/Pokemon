cmake_minimum_required(VERSION 3.0.0)
project(Pokemon VERSION 0.1.0)

FIND_PACKAGE(SDL2 REQUIRED)

MESSAGE( STATUS "CMAKE_BUILD_TYPE: " ${CMAKE_BUILD_TYPE})    
MESSAGE( STATUS "CMAKE_CXX_FLAGS: " ${CMAKE_CXX_FLAGS})

include(CTest)
enable_testing()

add_executable(Pokemon main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
