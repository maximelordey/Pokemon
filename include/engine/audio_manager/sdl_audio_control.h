#ifndef SDL_AUDIO_CONTROL_H
#define SDL_AUDIO_CONTROL_H

#include "iaudio_control.h"
#include <cstdint>

class SdlAudioControl : public IAudioControl {
	public:
		SdlAudioControl(uint32_t channel);
		~SdlAudioControl();

		void pause() override;

		void unpause() override;

		bool isPaused() const override;

	private:
		uint32_t _channel;
};

#endif