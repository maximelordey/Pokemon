#ifndef IAUDIO_PLAYER_H
#define IAUDIO_PLAYER_H

#include "iaudio_file.h"

class IAudioPlayer {
	public:
		virtual void playAudio(const IAudioFile& audioFile) = 0;

		virtual void stopAudio() = 0;

		virtual bool isPlaying() const = 0;
};

#endif
