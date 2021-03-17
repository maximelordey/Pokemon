#ifndef SPECIE_H
#define SPECIE_H

#include <vector>

#include "type.h"
#include "experience_curve.h"
#include "stats.h"
#include "height.h"
#include "weight.h"
#include "identifier.h"
#include "translation.h"

typedef struct {
	Identifier _identifier;
	Translation _name;
	std::vector<Type> _types;
	ExperienceCurve _experienceCurve;
	Height _height;
	Weight _weight;
	Stats _baseStats;
	Stats _baseEv;
} Specie;

#endif
