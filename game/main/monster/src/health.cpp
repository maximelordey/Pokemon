#include "health.h"

Health::Health()
	: _gauge()
{}

Health::Health(uint32_t healthMax)
	: _gauge(healthMax)
{}
