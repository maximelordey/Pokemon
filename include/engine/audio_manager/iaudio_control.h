#ifndef IAUDIO_COMMAND_H
#define IAUDIO_COMMAND_H

#include "iaudio_file.h"

class IAudioControl {
    public:
        virtual void pause() = 0;
        
        virtual void unpause() = 0;

        virtual bool isPaused() const = 0;
};
#endif
