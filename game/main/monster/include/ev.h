#ifndef EV_H
#define EV_H

#include <cstdint>
#include "gauge.h"

class Ev {
	public:
		Ev();
		Ev(uint32_t stat_limit);

	public:
		Gauge _health;
		Gauge _attack;
		Gauge _defence;
		Gauge _attackSpe;
		Gauge _defenceSpe;
		Gauge _speed;
};

#endif
