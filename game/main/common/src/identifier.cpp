#include "identifier.h"

Identifier::Identifier() 
	: _identifier()
{}

Identifier::Identifier(const char* identifier)
	: _identifier(identifier)
{}

Identifier::Identifier(const std::string& identifier)
	: _identifier(identifier)
{}

bool Identifier::isEqualTo(const Identifier& identifier) const {
	return _identifier.compare(identifier._identifier) == 0;
}

bool Identifier::isGreaterThan(const Identifier& identifier) const {
	return _identifier.compare(identifier._identifier) > 0;
}

bool Identifier::isLesserThan(const Identifier& identifier) const {
	return _identifier.compare(identifier._identifier) < 0;
}

bool Identifier::operator==(const Identifier& identifier) const {
	return this->isEqualTo(identifier);
}

bool Identifier::operator!=(const Identifier& identifier) const {
	return !this->isEqualTo(identifier);
}

bool Identifier::operator<(const Identifier& identifier) const {
	return this->isLesserThan(identifier);
}

bool Identifier::operator>(const Identifier& identifier) const {
	return this->isGreaterThan(identifier);
}
