#include "iv.h"

const uint32_t Iv::DEFAULT_LIMIT = 31u;

Iv::Iv() 
	: _health(DEFAULT_LIMIT), _attack(DEFAULT_LIMIT), _defence(DEFAULT_LIMIT),
	 _attackSpe(DEFAULT_LIMIT), _defenceSpe(DEFAULT_LIMIT), _speed(DEFAULT_LIMIT)
{}

Iv::Iv(uint32_t limit) 
	: _health(limit), _attack(limit), _defence(limit),
	 _attackSpe(limit), _defenceSpe(limit), _speed(limit)
{}
