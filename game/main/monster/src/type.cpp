#include "type.h"

Type::Type()
	: _identifier(), _name(), _weaknesses()
{}

Type::Type(const Identifier& identifier)
	: _identifier(identifier), _name(), _weaknesses()
{}

bool Type::isEqualTo(const Type &type) const {
	return _identifier == type._identifier;
}

bool Type::operator==(const Type &type) const {
	return this->isEqualTo(type);
}

bool Type::operator!=(const Type &type) const {
	return !this->isEqualTo(type); 
}

bool Type::operator<(const Type &type) const {
	return _identifier < type._identifier;
}

bool Type::operator>(const Type &type) const {
	return _identifier > type._identifier;
}
