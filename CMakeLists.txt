cmake_minimum_required(VERSION 3.0.0)
project(Pokemon VERSION 0.0.0)

find_package(PkgConfig)

pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(SDL2_MIXER REQUIRED SDL2_mixer)
pkg_check_modules(SDL2_IMAGE REQUIRED SDL2_image)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_MIXER_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

message( STATUS "CMAKE_BUILD_TYPE: " ${CMAKE_BUILD_TYPE})
message( STATUS "CMAKE_CXX_FLAGS: " ${CMAKE_CXX_FLAGS})
message( STATUS "CMAKE_CXX_STANDARD: " ${CMAKE_CXX_STANDARD})

include(CTest)
enable_testing()

add_executable(Pokemon main.cpp)
target_link_libraries(Pokemon ${SDL2_LIBRARIES} ${SDL2_MIXER_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
