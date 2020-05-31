class ISoundManager {
	public:
		virtual int increase(uint8_t value) = 0;
		virtual int decrease(uint8_t value) = 0;
		virtual int setVolume(uint8_t volume) = 0;
		virtual uint8_t getVolume() = 0;
		virtual int pause() = 0;
		virtual int unpause() = 0;
		virtual int stopMusic() = 0;
		virtual int loadMusic(String path) = 0;
		virtual int loadEffect(String path) = 0;
		virtual bool isPlaying() = 0;
}
