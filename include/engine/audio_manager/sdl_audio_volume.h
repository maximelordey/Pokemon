#ifndef SDL_AUDIO_VOLUME_H
#define SDL_AUDIO_VOLUME_H

#include "iaudio_volume.h"

class SdlAudioVolume: public IAudioVolume {
	public:
		static const int32_t GET_VOLUME;

		SdlAudioVolume();
		~SdlAudioVolume();

		void increase(uint32_t value) override;

		void decrease(uint32_t value) override;

		void setVolume(uint32_t volume) override;

		uint32_t getVolume() const override;
};

#endif