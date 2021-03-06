#ifndef MOVE_H
#define MOVE_H

#include "move_accuracy.h"
#include "move_power.h"
#include "move_class.h"
#include "identifier.h"
#include "translation.h"
#include "type.h"
#include "move_power_point.h"
#include "move_effect.h"

typedef struct {
	Identifier _identifier;
	Translation _name;
	Type _type;
	MoveClass _moveClass;
	MoveAccuracy _moveAccuracy;
	MovePower _movePower;
	MovePowerPoint _movePowerPoint;
	MoveEffect _effect;
} Move;

#endif
