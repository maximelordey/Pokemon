#include "move.h"

Move::Move()
	: _identifier(), _name(), _type(), _moveClass()
{}

Move::Move(const MoveCreateInfo& info) 
	: _identifier(info._identifier), _name(info._name), _type(info._type),
	_moveClass(info._moveClass)
{}