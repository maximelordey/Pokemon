#ifndef NATURE_H
#define NATURE_H

#include "coefficient.h"
#include "identifier.h"
#include "translation.h"

typedef struct {
	Identifier _identifier;
	Translation _name;
	Coefficient _attack;
	Coefficient _defence;
	Coefficient _attackSpe;
	Coefficient _defenceSpe;
	Coefficient _speed;
} Nature;

#endif
