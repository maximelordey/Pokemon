#ifndef MOVE_CLASS_H
#define MOVE_CLASS_H

#include "identifier.h"
#include "translation.h"

class MoveClass {
	public:
		MoveClass();
		MoveClass(const Identifier& identifier);
	public:
		Identifier _identifier;
		Translation _name;
};

#endif
