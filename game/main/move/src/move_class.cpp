#include "move_class.h"

MoveClass::MoveClass() 
	: _identifier(), _name()
{}

MoveClass::MoveClass(const Identifier& identifier) 
	: _identifier(identifier), _name()
{}

bool MoveClass::isEqualTo(const MoveClass& moveClass) const {
	return _identifier == moveClass._identifier;
}

bool MoveClass::operator==(const MoveClass& moveClass) const {
	return this->isEqualTo(moveClass);
}

bool MoveClass::operator!=(const MoveClass& moveClass) const {
	return !this->isEqualTo(moveClass);
}
