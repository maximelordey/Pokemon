#ifndef SDL_AUDIO_CONTROL_H
#define SDL_AUDIO_CONTROL_H

#include "iaudio_control.h"
#include <cstdint>

class SdlAudioControl : public IAudioControl {
	public:
		static const int8_t PAUSED; 

		SdlAudioControl();
		~SdlAudioControl();

		void pause() override;

		void unpause() override;

		bool isPaused() const override;
};

#endif