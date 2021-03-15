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
#include "nature.h"
#include "translation.h"
#include "identifier.h"

class Pokemon {
	private:
		static uint32_t getStat(uint32_t _baseStat, uint32_t iv, uint32_t ev, Level level, Coefficient coefficient);
	
	public:
		Pokemon();
		Pokemon(const PokemonCreateInfo& infos);

		uint32_t getAttack() const;
		uint32_t getDefence() const;
		uint32_t getAttackSpe() const;
		uint32_t getDefenceSpe() const;
		uint32_t getSpeed() const;

	public:
		Identifier _identifier;
		Translation _name;
		Specie _specie;
		Height _height;
		Weight _weight;
		Health _health;
		Iv _iv;
		Ev _ev;
		Nature _nature;
		Level _level;
		Experience _experience;
};

#endif
