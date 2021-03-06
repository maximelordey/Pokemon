#ifndef HEALTH_H
#define HEALTH_H

#include <cstdint>
#include "gauge.h"

class Health {
	public:
		Health();
		Health(uint32_t healthMax);
	public:
		Gauge _gauge;
};

#endif
