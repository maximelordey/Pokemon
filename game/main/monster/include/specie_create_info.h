#ifndef SPECIE_CREATE_INFO_H
#define SPECIE_CREATE_INFO_H

#include <string>
#include <vector>
#include "stats.h"
#include "height.h"
#include "weight.h"
#include "identifier.h"
#include "translation.h"

typedef struct SpecieCreateInfo {
	Identifier _identifier;
	Translation _names;
	std::vector<Type> _types;
	const IExperienceCurve* _pExperienceCurve;
	Height _Height;
	Weight _Weight;
	Stats _BaseStats;
	Stats _BaseEv;
} SpecieCreateInfo;

#endif
