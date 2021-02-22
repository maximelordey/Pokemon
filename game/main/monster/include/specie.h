#ifndef SPECIE_H
#define SPECIE_H

#include <string>
#include <vector>
#include <cstdint>

#include "type.h"
#include "experience_curve.h"

class Specie {
	public:
		Specie();
		Specie(const SpecieCreateInfo &infos);

	public:
		std::string _name;
		std::vector<Type> _types;
		std::vector<uint32_t> _baseStats;
		std::vector<uint32_t> _ev;
		float _size;
		float _weight;
		ExperienceCurve _experienceCurve;
};

#endif
