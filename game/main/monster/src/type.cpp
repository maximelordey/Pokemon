#include "type.h"

Type::Type()
	: _name(), _weaknesses()
{}

Type::Type(const std::string &name)
	: _name(name), _weaknesses()
{}
		
Type::Type(const char *name)
	: _name(name), _weaknesses()
{}

bool Type::isEqualTo(const Type &type) const {
	return (_name.compare(type._name) == 0);
}

bool Type::operator==(const Type &type) const {
	return this->isEqualTo(type);
}

bool Type::operator!=(const Type &type) const {
	return !this->isEqualTo(type); 
}

bool Type::operator<(const Type &type) const {
	return (_name.compare(type._name) < 0);
}

bool Type::operator>(const Type &type) const {
	return (_name.compare(type._name) > 0);
}
