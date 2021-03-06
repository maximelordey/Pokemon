#ifndef POKEMON_H
#define POKEMON_H

#include <string>

#include "pokemon_create_info.h"
#include "specie.h"
#include "height.h"
#include "weight.h"
#include "health.h"
#include "level.h"
#include "experience.h"
#include "iv.h"
#include "ev.h"

class Pokemon {
	public:
		Pokemon();
		Pokemon(PokemonCreateInfo infos);

	public:
		std::string _name;
		Specie _specie;
		Height _height;
		Weight _weight;
		Health _health;
		Level _level;
		Experience _experience;
		Iv _iv;
		Ev _ev;
};

#endif
