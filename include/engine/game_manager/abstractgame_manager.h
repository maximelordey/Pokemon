#ifndef ABSTRACT_GAME_MANAGER_H
#define ABSTRACT_GAME_MANAGER_H

#include "igame_manager.h"
#include "isound_manager.h"
#include "ivideo_manager.h"
#include "iaction_manager.h"
#include "iaction_command.h"
#include "irenderer.h"

class AbstractGameManager: public IGameManager {
	public:
		AbstractGameManager(ISoundManager& soundManager, IActionManager& actionManager, IVideoManager& videoManager);
		~AbstractGameManager();

		void run();
		double getFramePerSeconds() const;
		void setFramePerSeconds(double framePerSeconds);

		ISoundManager& getSoundManager() const;
		IVideoManager& getVideoManager() const;
		IActionManager& getActionManager() const;

	protected:
		virtual void processAction(IActionCommand& action) = 0;
		virtual void update(double elapsed) = 0;
		virtual void render(IRenderer& render) = 0;
}

#endif
