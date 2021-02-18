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

Iv::Iv(const Iv &iv) 
	: _health(iv._health), _attack(iv._attack), _defence(iv._defence),
	 _attackSpe(iv._attackSpe), _defenceSpe(iv._defenceSpe), _speed(iv._speed)
{}

Iv::Iv(Iv &&iv)
	: _health(iv._health), _attack(iv._attack), _defence(iv._defence),
	 _attackSpe(iv._attackSpe), _defenceSpe(iv._defenceSpe), _speed(iv._speed)
{}

Iv& Iv::operator=(const Iv &iv) {
	if (this != &iv) {
		_health = iv._health;
		_attack = iv._attack;
		_defence = iv._defence;
		_attackSpe = iv._attackSpe;
		_defenceSpe = iv._defenceSpe;
		_speed = iv._speed;
	}
	return *this;
}

Iv& Iv::operator=(Iv &&iv) {
	if (this != &iv) {
		_health = iv._health;
		_attack = iv._attack;
		_defence = iv._defence;
		_attackSpe = iv._attackSpe;
		_defenceSpe = iv._defenceSpe;
		_speed = iv._speed;
	}
	return *this;
}
