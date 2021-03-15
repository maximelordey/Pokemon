#include "move.h"

Move::Move()
	: _identifier(), _name(), _type(), _moveClass(),
	 _moveAccuracy(), _movePower(), _movePowerPoint()
{}

Move::Move(const MoveCreateInfo& info) 
	: _identifier(info._identifier), _name(info._name), _type(info._type),
	_moveClass(info._moveClass), _moveAccuracy(info._moveAccuracy),
	_movePower(info._movePower), _movePowerPoint(info._movePowerPoint)
{}
