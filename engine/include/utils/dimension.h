#ifndef DIMENSION_H
#define DIMENSION_H

#include <cstdint>

class Dimension {
	public:
		Dimension();
		Dimension(uint32_t width, uint32_t height);
		Dimension(const Dimension& dimension);
		Dimension(Dimension&& dimension);
		~Dimension();

		Dimension& operator=(const Dimension& dimension);
		Dimension& operator=(Dimension&& dimension);

	public:
		uint32_t _width;
		uint32_t _height;
};

#endif
