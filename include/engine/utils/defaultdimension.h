#ifndef DEFAULT_DIMENSION_H
#define DEFAULT_DIMENSION_H

#include "idimension.h"

class DefaultDimension : public IDimension{
    public:
        DefaultDimension(uint32_t width, uint32_t height);
        ~DefaultDimension();

		uint32_t getWidth() const override;
		uint32_t getHeight() const override;

		void setSize(uint32_t width, uint32_t height) override;

    private:
        uint32_t _width;
        uint32_t _height;
};

#endif