#ifndef POKEMON_H
#define POKEMON_H

#include <memory>

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

class Pokemon;
typedef std::unique_ptr<Pokemon> UniquePokemon;

class Pokemon{
	Identifier _identifier;
	Translation _name;
	Specie _specie;
	Height _height;
	Weight _weight;
	Health _health;
	Level _level;
	Experience _experience;
	Iv _bonusIvHealth;
	Iv _bonusIvAttack;
	Iv _bonusIvDefence;
	Iv _bonusIvAttackSpe;
	Iv _bonusIvDefenceSpe;
	Iv _bonusIvSpeed;
	Ev _bonusEvHealth;
	Ev _bonusEvAttack;
	Ev _bonusEvDefence;
	Ev _bonusEvAttackSpe;
	Ev _bonusEvDefenceSpe;
	Ev _bonusEvSpeed;
	Nature _nature;
};

#endif
