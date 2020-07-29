#include "sdl_audio_file.h"

SdlAudioFile::SdlAudioFile(const std::string& path){
	_music = Mix_LoadMUS(path.c_str());
}

SdlAudioFile::~SdlAudioFile(){
	Mix_FreeMusic(_music);
}

Mix_Music* SdlAudioFile::getFile() const {
	return _music;
}
