#include "language.h"

Language::Language()
	: _identifier(), _name()
{}
Language::Language(const Identifier& identifier)
	: _identifier(identifier), _name()
{}

bool Language::operator==(const Language& language) const {
	return _identifier == language._identifier;
}

bool Language::operator!=(const Language& language) const {
	return _identifier != language._identifier;
}

bool Language::operator>(const Language& language) const {
	return _identifier > language._identifier;
}

bool Language::operator<(const Language& language) const {
	return _identifier < language._identifier;
}
