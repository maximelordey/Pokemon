#include "audio_file_loader.h"
#include "sdl_audio_file.h"

IAudioFileLoader::IAudioFileLoader() {}

IAudioFileLoader::~IAudioFileLoader() {}

IAudioFile* IAudioFileLoader::load(const std::string& path) const {
	return new SdlAudioFile(path);
}
