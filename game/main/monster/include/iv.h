#ifndef IV_H
#define IV_H

#include <cstdint> 
#include "gauge.h"

class Iv {
	public:
		static const uint32_t DEFAULT_LIMIT;

	public:
		Iv();
		Iv(uint32_t limit);
		Iv(const Iv &iv);
		Iv(Iv &&iv);

		Iv& operator=(const Iv &iv);
		Iv& operator=(Iv &&iv);
		
	public:
		Gauge _health;
		Gauge _attack;
		Gauge _defence;
		Gauge _attackSpe;
		Gauge _defenceSpe;
		Gauge _speed;
};

#endif
