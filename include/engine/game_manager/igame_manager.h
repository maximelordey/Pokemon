class IGameManager {
	public:
		virtual void run() = 0;
		virtual double getFramePerSeconds() = 0;
		virtual void setFramePerSeconds(double fps) = 0;
		virtual ISoundManager getSoundManager() = 0;
		virtual IVideoManager getVideoManager() = 0;
		virtual IActionManager getActionManager() = 0;
}
