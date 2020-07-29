#include "sdl_audio_player.h"
#include "sdl_audio_file.h"

int32_t SdlAudioPlayer::INFINITE = -1;
int8_t SdlAudioPlayer::PLAYING = 1;

SdlAudioPlayer::SdlAudioPlayer() {}

SdlAudioPlayer::~SdlAudioPlayer() {}

void SdlAudioPlayer::playAudio(SdlAudioFile& audioFile) {
	Mix_PlayMusic(audioFile.getFile(), INFINITE);
}

void SdlAudioPlayer::stopAudio() {
	Mix_HaltMusic();
}

bool SdlAudioPlayer::isPlaying() const {
	return Mix_PlayingMusic() == PLAYING;
}
