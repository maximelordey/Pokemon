#ifndef ISOUND_MANAGER_H
#define ISOUND_MANAGER_H

#include <cstdint>
#include <iostream>

class ISoundManager {
	public:
		virtual int increase(uint8_t value) = 0;
		virtual int decrease(uint8_t value) = 0;
		virtual int setVolume(uint8_t volume) = 0;
		virtual uint8_t getVolume() const = 0;

		virtual int pause() = 0;
		virtual int unpause() = 0;
		virtual int stopMusic() = 0;

		virtual int loadMusic(std::string& path) = 0;
		virtual int loadEffect(std::string& path) = 0;
		virtual bool isPlaying() const = 0;
}

#endif
