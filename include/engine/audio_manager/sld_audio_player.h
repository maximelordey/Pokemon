#ifndef SDL_AUDIO_PLAYER_H
#define SDL_AUDIO_PLAYER_H

#include "iaudio_player.h"

class SdlAudioPlayer : public IAudioPlayer {
    public:
        void playAudio(const IAudioFile& audioFile) override;
};

#endif
