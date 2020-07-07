
#include "sdl_audio_control.h"
#include <SDL_mixer.h>

SdlAudioControl::SdlAudioControl(uint32_t channel)
    : _channel(channel)
{}

SdlAudioControl::~SdlAudioControl(){}

void SdlAudioControl::pause(){
    Mix_Pause(_channel);
}

void SdlAudioControl::unpause() {
    Mix_Resume(_channel);
}

bool SdlAudioControl::isPaused() const {
    return Mix_Paused(_channel) == 1;
}