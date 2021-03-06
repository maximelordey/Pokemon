#include "ev.h"
#include <algorithm>

Ev::Ev()
	: _health(), _attack(), _defence(),
	 _attackSpe(), _defenceSpe(), _speed()
{}

Ev::Ev(uint32_t stat_limit)
	: _health(stat_limit), _attack(stat_limit), _defence(stat_limit),
	 _attackSpe(stat_limit), _defenceSpe(stat_limit), _speed(stat_limit)
{}
