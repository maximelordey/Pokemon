#ifndef IAUDIO_FILE_LOADER_H
#define IAUDIO_FILE_LOADER_H

#include <iostream>

#include "iaudio_file.h"

class IAudioFileLoader {
    public:
        IAudioFile& load(const std::string& path) const;
};

#endif
