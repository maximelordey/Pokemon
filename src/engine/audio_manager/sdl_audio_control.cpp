
#include "sdl_audio_control.h"

SdlAudioControl::SdlAudioControl()
    : _paused(false)
{}

SdlAudioControl::~SdlAudioControl(){}

void SdlAudioControl::pause(){
    _paused = true;
}

void SdlAudioControl::unpause() {
    _paused = false;
}

bool SdlAudioControl::isPaused() const {
    return _paused;
}