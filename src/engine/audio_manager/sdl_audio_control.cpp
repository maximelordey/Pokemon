
#include "sdl_audio_control.h"
#include <SDL_mixer.h>


const int8_t SdlAudioControl::PAUSED = 1;

SdlAudioControl::SdlAudioControl(){}

SdlAudioControl::~SdlAudioControl(){}

void SdlAudioControl::pause(){
    Mix_PauseMusic();
}

void SdlAudioControl::unpause() {
    Mix_ResumeMusic();
}

bool SdlAudioControl::isPaused() const {
    return Mix_PausedMusic() == PAUSED;
}