#ifndef NATURE_H
#define NATURE_H

#include <string>

#include "coefficient.h"
#include "identifier.h"

class Nature {
	public:
		static const float DEFAULT_VALUE;

	public:
		Nature();
		Nature(const Identifier& identifier);

	public:
		Identifier _identifier;
		std::string _name;
		Coefficient _attack;
		Coefficient _defence;
		Coefficient _attackSpe;
		Coefficient _defenceSpe;
		Coefficient _speed;
};

#endif
