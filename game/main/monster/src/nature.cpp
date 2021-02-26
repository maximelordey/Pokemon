#include "nature.h"

Nature::Nature()
	: _name(), _attack(0.0f), _defence(0.0f), _attackSpe(0.0f),
	 _defenceSpe(0.0f), _speed(0.0f)
{}

Nature::Nature(const char* name)
	: _name(name), _attack(0.0f), _defence(0.0f), _attackSpe(0.0f),
	 _defenceSpe(0.0f), _speed(0.0f)
{}

Nature::Nature(const std::string name)
	: _name(name), _attack(0.0f), _defence(0.0f), _attackSpe(0.0f),
	 _defenceSpe(0.0f), _speed(0.0f)
{}