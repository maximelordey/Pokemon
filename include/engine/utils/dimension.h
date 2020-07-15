#ifndef DIMENSION_H
#define DIMENSION_H

#include "idimension.h"

class Dimension : public IDimension{
	public:
		Dimension(uint32_t width, uint32_t height);
		Dimension(Dimension& dimension);
		Dimension(Dimension&& dimension);
		~Dimension();

		uint32_t getWidth() const override;
		uint32_t getHeight() const override;

		void setSize(uint32_t width, uint32_t height) override;

	private:
		uint32_t _width;
		uint32_t _height;
};

#endif
