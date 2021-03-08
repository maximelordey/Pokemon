#ifndef LANGUAGE_H
#define LANGUAGE_H

#include "translation.h"

class Language {
		Language();
		Language(const wchar_t* _name);
		Language(std::wstring &_name);
		Language(Translation &_name);

		bool operator==(const Language& language) const;
		bool operator!=(const Language& language) const;
		bool operator>(const Language& language) const;
		bool operator<(const Language& language) const;
		
	public:
		Translation _name;
};

#endif
