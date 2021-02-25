#ifndef SPECIE_CREATE_INFO_H
#define SPECIE_CREATE_INFO_H

#include <string>
#include "base_stats.h"
#include "base_ev.h"
#include "height.h"
#include "weight.h"

struct SpecieCreateInfo {
	const char*	_pName;
	const Type*	_pTypes;
	uint32_t _typesCount;
	const IExperienceCurve* _pExperienceCurve;
	const Height& _rHeight;
	const Weight& _rWeight;
	const Stats& _rBaseStats;
	const Stats& _rBaseEv;
} SpecieCreateInfo;


#endif;
