#ifndef LEVEL_H
#define LEVEL_H

#include <cstdint>
#include "gauge.h"

class Level {
	public:
		Level();
		Level(uint32_t levelMax);

	public:
		Gauge _gauge;
};

#endif
