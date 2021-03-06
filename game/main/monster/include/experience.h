#ifndef EXPERIENCE_H
#define EXPERIENCE_H

#include <cstdint>
#include "gauge.h"

class Experience {
	public:
		Experience();
		Experience(uint32_t experienceMax);

	public:
		Gauge _gauge;
};

#endif
