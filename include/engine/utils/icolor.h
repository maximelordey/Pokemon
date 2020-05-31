include <cstdint>;

class IColor {

	public:
		virtual uint8_t getRed() = 0;
		virtual uint8_t getGreen() = 0;
		virtual uint8_t getBlue() = 0;
		virtual uint8_t getAlpha() = 0;
}
