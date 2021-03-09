#include "nature.h"

const float Nature::DEFAULT_VALUE = 1.0f;

Nature::Nature()
	: _identifier(), _name(), _attack(DEFAULT_VALUE), _defence(DEFAULT_VALUE),
	 _attackSpe(DEFAULT_VALUE), _defenceSpe(DEFAULT_VALUE), _speed(DEFAULT_VALUE)
{}

Nature::Nature(const Identifier& identifier)
	: _identifier(identifier), _name(), _attack(DEFAULT_VALUE), _defence(DEFAULT_VALUE),
	 _attackSpe(DEFAULT_VALUE), _defenceSpe(DEFAULT_VALUE), _speed(DEFAULT_VALUE)
{}
