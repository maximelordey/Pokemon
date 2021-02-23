#ifndef SPECIE_H
#define SPECIE_H

#include <string>
#include <vector>
#include <cstdint>

#include "type.h"
#include "experience_curve.h"
#include "specie_create_info.h"

class Specie {
	public:
		Specie();
		Specie(const SpecieCreateInfo &infos);

	public:
		std::string _name;
		std::vector<Type> _types;
		ExperienceCurve _experienceCurve;
		float _size;
		float _weight;
		uint32_t _baseHealth;
		uint32_t _baseAttack;
		uint32_t _baseDefence;
		uint32_t _baseAttackSpe;
		uint32_t _baseDefenceSpe;
		uint32_t _baseSpeed;
};

#endif
