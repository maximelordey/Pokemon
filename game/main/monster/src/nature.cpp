#include "nature.h"

const float Nature::DEFAULT_VALUE = 1.0f;

Nature::Nature()
	: _name(), _attack(DEFAULT_VALUE), _defence(DEFAULT_VALUE),
	 _attackSpe(DEFAULT_VALUE), _defenceSpe(DEFAULT_VALUE), _speed(DEFAULT_VALUE)
{}

Nature::Nature(const char* name)
	: _name(name), _attack(DEFAULT_VALUE), _defence(DEFAULT_VALUE),
	 _attackSpe(DEFAULT_VALUE), _defenceSpe(DEFAULT_VALUE), _speed(DEFAULT_VALUE)
{}

Nature::Nature(const std::string name)
	: _name(name), _attack(DEFAULT_VALUE), _defence(DEFAULT_VALUE),
	 _attackSpe(DEFAULT_VALUE), _defenceSpe(DEFAULT_VALUE), _speed(DEFAULT_VALUE)
{}