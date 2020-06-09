#ifndef IAUDIO_VOLUME_H
#define IAUDIO_VOLUME_H

#include <cstdint>

class IAudioVolume {
    public:
        virtual void increase(uint32_t value) = 0;

        virtual void decrease(uint32_t value) = 0;

        virtual void setVolume(uint32_t volume) = 0;

        virtual uint32_t getVolume() const = 0;
}
#endif