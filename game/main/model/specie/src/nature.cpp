#include "nature.hpp"

Nature::Nature()
	: identifier()
{}

Nature::Nature(const Identifier& identifier)
	: identifier(identifier)
{}


bool Nature::isEqualTo(const Nature& nature) const{
	identifier == nature.identifier;
}

bool Nature::isLesserThan(const Nature& nature) const{
	identifier < nature.identifier;
}

bool Nature::isGreaterThan(const Nature& nature) const{
	identifier > nature.identifier;
}


bool Nature::operator==(const Nature& nature) const{
	return this->isEqualTo(nature);
}

bool Nature::operator!=(const Nature& nature) const{
	return !this->isEqualTo(nature);
}

bool Nature::operator<(const Nature& nature) const{
	return this->isLesserThan(nature);
}

bool Nature::operator>(const Nature& nature) const{
	return this->isGreaterThan(nature);
}
