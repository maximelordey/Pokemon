#ifndef WEAKNESSES_H
#define WEAKNESSES_H

#include "type.h"
#include "coefficient.h"

typedef struct {
	std::map<Type, Coefficient> _content;
};

#endif
