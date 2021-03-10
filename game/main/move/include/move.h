#ifndef MOVE_H
#define MOVE_H

#include "move_create_info.h"
#include "identifier.h"
#include "translation.h"
#include "move_class.h"
#include "type.h"

class Move {
	public:
		Move();
		Move(const MoveCreateInfo& infos);

	public:
		Identifier _identifier;
		Translation _name;
		Type _type;
		MoveClass _moveClass;
};

#endif