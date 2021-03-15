#ifndef MOVE_POWER_POINT_H
#define MOVE_POWER_POINT_H

#include <cstdint>
#include "gauge.h"

class MovePowerPoint {
	public:
		MovePowerPoint();
		MovePowerPoint(uint32_t powerPointMax);
	
	public:
		Gauge _gauge;
};

#endif
