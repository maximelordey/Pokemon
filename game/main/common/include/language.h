#ifndef LANGUAGE_H
#define LANGUAGE_H

#include "text.h"
#include "identifier.h"

class Language {
		Language();
		Language(const Identifier& _name);

		bool operator==(const Language& language) const;
		bool operator!=(const Language& language) const;
		bool operator>(const Language& language) const;
		bool operator<(const Language& language) const;
		
	public:
		Identifier _identifier;
		Text _name;
};

#endif
