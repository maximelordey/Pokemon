#ifndef TYPE_H
#define TYPE_H

#include "weaknesses.h"
#include "coefficient.h"
#include "identifier.h"
#include "translation.h"

typedef struct {
	Identifier _identifier;
	Translation _name;
	Weaknesses _weaknesses;
} Type;

#endif
