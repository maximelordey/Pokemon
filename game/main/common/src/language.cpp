#include "language.h"

Language::Language()
	: _name()
{}
Language::Language(const wchar_t* _name)
	: _name(_name)
{}
Language::Language(std::wstring &_name)
	: _name(_name)
{}
Language::Language(Translation &_name)
	: _name(_name)
{}

bool Language::operator==(const Language& language) const {
	return _name._content.compare(language._name._content) == 0;
}

bool Language::operator!=(const Language& language) const {
	return _name._content.compare(language._name._content) != 0;
}

bool Language::operator>(const Language& language) const {
	return _name._content.compare(language._name._content) > 0;
}

bool Language::operator<(const Language& language) const {
	return _name._content.compare(language._name._content) < 0;
}
