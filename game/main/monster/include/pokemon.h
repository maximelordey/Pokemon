#ifndef POKEMON_H
#define POKEMON_H

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

typedef struct {
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
} Pokemon;

#endif
