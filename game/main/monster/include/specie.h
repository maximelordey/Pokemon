#ifndef SPECIE_H
#define SPECIE_H

#include <vector>

#include "type.h"
#include "experience_curve.h"
#include "height.h"
#include "weight.h"
#include "identifier.h"
#include "translation.h"
#include "stat.h"

typedef struct {
	Identifier _identifier;
	Translation _name;
	std::vector<Type> _types;
	ExperienceCurve _experienceCurve;
	Height _height;
	Weight _weight;
	Stat _baseHealth;
	Stat _baseAttack;
	Stat _baseDefence;
	Stat _baseAttackSpe;
	Stat _baseDefeceSpe;
	Stat _baseSpeed;
} Specie;

#endif
