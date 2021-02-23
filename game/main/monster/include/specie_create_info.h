#ifndef SPECIE_CREATE_INFO_H
#define SPECIE_CREATE_INFO_H

#include <string>

struct SpecieCreateInfo {
	const char* pName;
	const Type* pTypes;
	uint32_t typeCount;
	const IExperienceCurve* pExperienceCurve;
	float size;
	float weight;
	uint32_t baseHealth;
	uint32_t baseAttack;
	uint32_t baseDefence;
	uint32_t baseAttackSpe;
	uint32_t baseDefenceSpe;
	uint32_t baseSpeed;
};


#endif;
