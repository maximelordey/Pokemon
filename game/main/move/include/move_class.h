#ifndef MOVE_CLASS_H
#define MOVE_CLASS_H

#include "identifier.h"
#include "translation.h"

class MoveClass {
	public:
		MoveClass();
		MoveClass(const Identifier& identifier);

		bool isEqualTo(const MoveClass& moveClass) const;

		bool operator==(const MoveClass& moveClass) const;
		bool operator!=(const MoveClass& moveClass) const;
		
	public:
		Identifier _identifier;
		Translation _name;
};

#endif
