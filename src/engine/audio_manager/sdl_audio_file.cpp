#include "sdl_audio_file.h"

SdlAudioFile::SdlAudioFile(std::string& path){
	_music = Mix_LoadMUS(path.data);
}

SdlAudioFile::~SdlAudioFile(){
	Mix_FreeMusic(_music);
}

SdlAudioFile::getFile() const {
	return _music;
}