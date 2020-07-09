#include "sdl_audio_volume.h"

const int32_t SdlAudioVolume::GET_VOLUME = -1;
const int32_t SdlAudioVolume::MAX_VOLUME = MIX_MAX_VOLUME;
const int32_t SdlAudioVolume::MIN_VOLUME = 0;


SdlAudioVolume::SdlAudioVolume() {}

SdlAudioVolume::~SdlAudioVolume() {}

void SdlAudioVolume::increase(uint32_t value) {
	uint32_t volume = getVolume();
	setVolume(volume + value);
}

void SdlAudioVolume::decrease(uint32_t value) {
	uint32_t volume = getVolume();
	setVolume(volume - value);
}

void SdlAudioVolume::setVolume(uint32_t volume) {
	Mix_VolumeMusic(volume);
}

uint32_t SdlAudioVolume::getVolume() const {
	return Mix_VolumeMusic(GET_VOLUME);
}
