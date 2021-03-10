#ifndef TRANSLATION_H
#define TRANSLATION_H

#include <map>

#include "text.h"
#include "language.h"
#include "identifier.h"

class Translation {
	public:
		Translation();
		Translation(const Identifier& identifier);

	public:
		Identifier _identifier;
		std::map<Language, Text> _translations;
};

#endif
