#ifndef SDL_AUDIO_PLAYER_H
#define SDL_AUDIO_PLAYER_H

#include "iaudio_player.h"
#include <cstdint>

class SdlAudioPlayer : public IAudioPlayer {
    public:
		static const int32_t INFINITE;
		static const int8_t PLAYING;

		SdlAudioPlayer();
		~SdlAudioPlayer();

		void playAudio(SdlAudioFile& audioFile) override;

		void stopAudio() override;

		bool isPlaying() const override;
};

#endif
