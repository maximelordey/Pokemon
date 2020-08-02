#ifndef DIMENSION_H
#define DIMENSION_H

#include <cstdint>

class Dimension {
	public:
		Dimension(uint32_t width, uint32_t height);
		Dimension(const Dimension& dimension);
		Dimension(Dimension&& dimension);
		~Dimension();

		uint32_t getWidth() const;
		uint32_t getHeight() const;

		void setSize(uint32_t width, uint32_t height);

		Dimension& operator=(const Dimension& dimension);
		Dimension& operator=(Dimension&& dimension);

	private:
		uint32_t _width;
		uint32_t _height;
};

#endif
