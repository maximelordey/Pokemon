#ifndef BOX_H
#define BOX_H

#include <array>
#include "identifier.h"
#include "translation.h"
#include "pokemon.h"

class Box {
	public:
		Box();
		Box(const Identifier& indentifier);
		Box(const Identifier& indentifier, size_t size);
	public:
		Identifier _identifier;
		Translation _name;
		std::vector<Pokemon> _content;
};

#endif
