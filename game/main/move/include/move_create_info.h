#ifndef MOVE_CREATE_INFO_H
#define MOVE_CREATE_INFO_H

#include "identifier.h"
#include "translation.h"
#include "move_class.h"
#include "type.h"

typedef struct {
	Identifier _identifier;
	Translation _name;
	Type _type;
	MoveClass _moveClass;
} MoveCreateInfo;

#endif
