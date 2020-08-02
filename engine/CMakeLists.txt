cmake_minimum_required(VERSION 3.0.0)
project(GameEngine VERSION 1.0.0)

##### Check for SDL2, SDL2_Mixer, SDL2_Image
find_package(PkgConfig)

pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(SDL2_MIXER REQUIRED SDL2_mixer)
pkg_check_modules(SDL2_IMAGE REQUIRED SDL2_image)
##### Check for SDL2, SDL2_Mixer, SDL2_Image
##### Add libraries here.
add_library(Engine STATIC
"include/action_command/iaction_command.h"
"include/action_command/default_action_command.h"
"include/action_manager/iaction_manager.h"
"include/audio_manager/iaudio_command.h"
"include/audio_manager/iaudio_file.h"
"include/audio_manager/iaudio_file_loader.h"
"include/audio_manager/iaudio_manager.h"
"include/audio_manager/iaudio_player.h"
"include/audio_manager/iaudio_volume.h"
"include/event/ievent.h"
"include/event_manager/ievent_manager.h"
"include/game_manager/igame_manager.h"
"include/game_manager/abstract_game_manager.h"
"include/mapper/ievent_mapper.h"
"include/mapper/default_event_mapper.h"
"include/utils/icolor.h"
"include/utils/idimension.h"
"include/utils/ipoint.h"
"include/utils/irectangle.h"
"include/video/irenderer.h"
"include/video/itexture.h"
"include/video/iwindow.h"
)

##### Add libraries here.
set_target_properties(Engine PROPERTIES LINKER_LANGUAGE CXX)
##### Add directories here.
target_include_directories(Engine PUBLIC
"${CMAKE_CURRENT_SOURCE_DIR}/include/action_command"
"${CMAKE_CURRENT_SOURCE_DIR}/include/action_manager"
"${CMAKE_CURRENT_SOURCE_DIR}/include/audio_manager"
"${CMAKE_CURRENT_SOURCE_DIR}/include/event"
"${CMAKE_CURRENT_SOURCE_DIR}/include/event_manager"
"${CMAKE_CURRENT_SOURCE_DIR}/include/game_manager"
"${CMAKE_CURRENT_SOURCE_DIR}/include/mapper"
"${CMAKE_CURRENT_SOURCE_DIR}/include/utils"
"${CMAKE_CURRENT_SOURCE_DIR}/include/video"
)
##### Add directories here.

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)