#ifndef IDIMENSION_H
#define IDIMENSION_H

#include <cstdint>

class IDimension {

	public:
		virtual uint32_t getWidth() const = 0;
		virtual uint32_t getHeight() const = 0;

		virtual void setSize(uint32_t width, uint32_t height) = 0;

};

#endif
