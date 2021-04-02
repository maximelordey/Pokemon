#ifndef TYPE_H
#define TYPE_H

#include <map>
#include "identifier.h"
#include "translation.h"
#include "coefficient.h"

typedef struct Type Type;
typedef std::map<Type, Coefficient> Effectiveness;

struct Type {
	Identifier _identifier;
	Translation _name;
	Effectiveness _effectiveness;
};

#endif
