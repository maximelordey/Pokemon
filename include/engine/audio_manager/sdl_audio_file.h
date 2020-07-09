#ifndef SDL_AUDIO_FILE_H
#define SDL_AUDIO_FILE_H

#include "iaudio_file.h"
#include <SDL_mixer.h>
#include <string>

class SdlAudioFile: public IAudioFile {
	public:
		SdlAudioFile(std::string& path);
		~SdlAudioFile();

		Mix_Music& getFile() const;
	private:
		Mix_Music* _music;
};

#endif