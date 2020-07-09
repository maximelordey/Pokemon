#ifndef AUDIO_FILE_LOADER
#define AUDIO_FILE_LOADER

#include "iaudio_file_loader.h"
#include "iaudio_file.h"

class AudioFileLoader: public IAudioFileLoader {
    public:
		IAudioFileLoader();
		~IAudioFileLoader();

		IAudioFile* load(const std::string& path) const;
}

#endif
