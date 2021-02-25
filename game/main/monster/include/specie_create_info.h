#ifndef SPECIE_CREATE_INFO_H
#define SPECIE_CREATE_INFO_H

#include <string>
#include "stats.h"
#include "height.h"
#include "weight.h"

typedef struct SpecieCreateInfo {
	const char* _pName;
	const Type* _pTypes;
	uint32_t _typesCount;
	const IExperienceCurve* _pExperienceCurve;
	Height _Height;
	Weight _Weight;
	Stats _BaseStats;
	Stats _BaseEv;
} SpecieCreateInfo;


#endif;
