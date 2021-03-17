#ifndef TYPE_H
#define TYPE_H

#include <map>
#include "identifier.h"
#include "translation.h"
#include "coefficient.h"

typedef struct Type Type;
typedef struct Weaknesses Weaknesses;

struct Weaknesses{
	std::map<Type, Coefficient> _content;
};

struct Type{
	Identifier _identifier;
	Translation _name;
	Weaknesses _weaknesses;
};

#endif
