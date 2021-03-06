#ifndef POKEMON_H
#define POKEMON_H

#include <string>

#include "height.h"
#include "weight.h"
#include "health.h"
#include "level.h"
#include "experience.h"

class Pokemon {
	public:
		std::string _name;
		Height _height;
		Weight _weight;
		Health _health;
		Level _ level;
		Experience _experience;

};

#endif
