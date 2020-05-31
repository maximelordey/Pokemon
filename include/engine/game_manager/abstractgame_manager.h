public class AbstractGameManager: public IGameManager {
	public:
		AbstractGameManager(ISoundManager soundManager, IActionManager actionManager, IVideoManager videoManager);
		~AbstractGameManager();

		void run();
		double getFramePerSeconds();
		void setFramePerSeconds();
		ISoundManager getSoundManager();
		IVideoManager getVideoManager();
		IActionManager getActionManager();

	protected:
		virtual void processAction(IActionCommand &action) = 0;
		virtual void update(double elapsed) = 0;
		virtual void render(IRenderer &render) = 0;
}
