cmake_minimum_required(VERSION 3.0.0)
project(engine VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig)
pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(SDL2_MIXER REQUIRED SDL2_mixer)
pkg_check_modules(SDL2_IMAGE REQUIRED SDL2_image)

add_library(engine)

target_sources(engine PUBLIC
${CMAKE_CURRENT_SOURCE_DIR}/include/point.hpp
${CMAKE_CURRENT_SOURCE_DIR}/include/dimension.hpp
${CMAKE_CURRENT_SOURCE_DIR}/include/window.hpp
${CMAKE_CURRENT_SOURCE_DIR}/include/renderer.hpp
${CMAKE_CURRENT_SOURCE_DIR}/include/color.hpp
${CMAKE_CURRENT_SOURCE_DIR}/include/game_engine.hpp

)

target_sources(engine PRIVATE
${CMAKE_CURRENT_SOURCE_DIR}/src/game_engine.cpp
${CMAKE_CURRENT_SOURCE_DIR}/src/window.cpp
${CMAKE_CURRENT_SOURCE_DIR}/src/renderer.cpp
${CMAKE_CURRENT_SOURCE_DIR}/src/surface.cpp
${CMAKE_CURRENT_SOURCE_DIR}/src/texture.cpp
)

target_include_directories(engine PUBLIC 
${CMAKE_CURRENT_SOURCE_DIR}/include
${SDL2_INCLUDE_DIRS} 
${SDL2_MIXER_INCLUDE_DIRS} 
${SDL2_IMAGE_INCLUDE_DIRS}
)

target_link_libraries(engine PRIVATE
${SDL2_LIBRARIES} 
${SDL2_MIXER_LIBRARIES} 
${SDL2_IMAGE_LIBRARIES}
)
