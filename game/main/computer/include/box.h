#ifndef BOX_H
#define BOX_H

#include <vector>
#include <optional>
#include "identifier.h"
#include "translation.h"
#include "pokemon.h"

class Box {
	public:
		Box();
		Box(size_t size);

	public:
		std::vector<std::optional<Pokemon>> _content;
};

#endif
