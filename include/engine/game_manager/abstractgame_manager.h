#ifndef ABSTRACT_GAME_MANAGER_H
#define ABSTRACT_GAME_MANAGER_H

#include "igame_manager.h"
#include "iaudio_manager.h"
#include "ivideo_manager.h"
#include "iaction_manager.h"
#include "iaction_command.h"
#include "irenderer.h"

class AbstractGameManager: public IGameManager {
	public:
		AbstractGameManager(IAudioManager& audioManager, IActionManager& actionManager, IVideoManager& videoManager);
		~AbstractGameManager();

		void run() override;
		double getFramePerSeconds() const override;
		void setFramePerSeconds(double framePerSeconds) override;

		IAudioManager& getAudioManager() const override;
		IVideoManager& getVideoManager() const override;
		IActionManager& getActionManager() const override;

	protected:
		virtual void processAction(IActionCommand& action) = 0;
		virtual void update(double elapsed) = 0;
		virtual void render(IRenderer& render) = 0;
};
#endif
