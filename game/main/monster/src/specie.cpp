#include "specie.h"

Specie::Specie(const SpecieCreateInfo& info)
	: _name(info._pName), _types(info._typeCount, info._pTypes),
	_experienceCurve(info._pExperienceCurve), _height(info._pHeight),
	_weight(info._pWeight), _baseStats(info._pBaseStats), _baseEv(info._pBaseEv)
{}