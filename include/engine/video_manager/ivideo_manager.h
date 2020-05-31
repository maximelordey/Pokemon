class IVideoManager {
	public:
		virtual IWindow createWindow(String name, int posX, int posY, int width, int height, int flags) = 0;

}
