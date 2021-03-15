#ifndef MOVE_CREATE_INFO_H
#define MOVE_CREATE_INFO_H

#include "move_accuracy.h"
#include "move_power.h"
#include "move_class.h"
#include "identifier.h"
#include "translation.h"
#include "type.h"

typedef struct {
	Identifier _identifier;
	Translation _name;
	Type _type;
	MoveClass _moveClass;
	MoveAccuracy _accuracy;
	MovePower _power;
} MoveCreateInfo;

#endif
