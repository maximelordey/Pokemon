#ifndef MOVE_H
#define MOVE_H

#include "move_create_info.h"
#include "move_accuracy.h"
#include "move_power.h"
#include "move_class.h"
#include "identifier.h"
#include "translation.h"
#include "type.h"
#include "effect.h"

class Move {
	public:
		Move();
		Move(const MoveCreateInfo& infos);

	public:
		Identifier _identifier;
		Translation _name;
		Type _type;
		MoveClass _moveClass;
		MoveAccuracy _accuracy;
		MovePower _power;
		Effect _effect;
};

#endif