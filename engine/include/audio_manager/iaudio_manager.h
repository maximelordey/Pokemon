#ifndef IAUDIO_MANAGER_H
#define IAUDIO_MANAGER_H

#include <cstdint>
#include <iostream>

class IAudioManager {
	public:
		virtual void increase(uint32_t value) = 0;
		virtual void decrease(uint32_t value) = 0;
		virtual void setVolume(uint32_t volume) = 0;
		virtual uint32_t getVolume() const = 0;

		virtual void pause() = 0;
		virtual void unpause() = 0;
		virtual void stopMusic() = 0;		
		virtual bool isPlaying() const = 0;

		virtual void playMusic(std::string& path) = 0;
		virtual void playEffect(std::string& path) = 0;
};

#endif
