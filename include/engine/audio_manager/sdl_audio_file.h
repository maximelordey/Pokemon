#ifndef SDL_AUDIO_FILE_H
#define SDL_AUDIO_FILE_H

#include <string>
#include <SDL_mixer.h>
#include "iaudio_file.h"

class SdlAudioFile: public IAudioFile {
	public:
		SdlAudioFile(const std::string& path);
		~SdlAudioFile();

		Mix_Music* getFile() const;
	
	private:
		Mix_Music* _music;
};

#endif
