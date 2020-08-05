#ifndef IGAME_MANAGER_H
#define IGAME_MANAGER_H

#include "iaudio_manager.h"
#include "ivideo_manager.h"
#include "iaction_manager.h"

class IGameManager {
	public:
		virtual void run() = 0;
		virtual double getFramePerSeconds() const = 0;
		virtual void setFramePerSeconds(double fps) = 0;

		virtual IAudioManager& getAudioManager() const = 0;
		virtual IVideoManager& getVideoManager() const = 0;
		virtual IActionManager& getActionManager() const = 0;
};
#endif
