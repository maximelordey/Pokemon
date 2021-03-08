#ifndef TEXT_T
#define TEXT_T

#include <map>

#include "language.h"
#include "translation.h"

class Text {
	public:
		Text();
	public:
		std::map<Language, Translation> _translations;
};

#endif
