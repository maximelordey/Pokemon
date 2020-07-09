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

		void playAudio(IAudioFile& audioFile) override;

		void stopAudio() override;

		bool isPlaying() const override;

	private:
		IAudioFile* _currentAudioFile;
};

#endif
