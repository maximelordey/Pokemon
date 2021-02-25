#ifndef SPECIE_H
#define SPECIE_H

#include <string>
#include <vector>
#include <cstdint>

#include "type.h"
#include "experience_curve.h"
#include "specie_create_info.h"
#include "base_stats.h"
#include "base_ev.h"
#include "height.h"
#include "weight.h"

class Specie {
	public:
		Specie();
		Specie(const SpecieCreateInfo &infos);

	public:
		std::string _name;
		std::vector<Type> _types;
		ExperienceCurve _experienceCurve;
		Height _height;
		Weight _weight;
		BaseStats _baseStats;
		BaseEv _baseEv;
};

#endif
