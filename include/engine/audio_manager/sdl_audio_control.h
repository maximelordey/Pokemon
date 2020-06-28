#ifndef SDL_AUDIO_CONTROL_H
#define SDL_AUDIO_CONTROL_H

#include "iaudio_control.h"

class SdlAudioControl : public IAudioControl {
    public:
        SdlAudioControl();
        ~SdlAudioControl();

        void pause() override;
        
        void unpause() override;

        bool isPaused() const override;

    private:
        bool _paused;
};

#endif