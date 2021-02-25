#include "specie.h"

Specie::Specie(const SpecieCreateInfo& info)
	: _name(info._pName), _types(info._pTypes, info._pTypes + info._typesCount),
	_experienceCurve(info._pExperienceCurve), _height(info._Height),
	_weight(info._Weight), _baseStats(info._BaseStats), _baseEv(info._BaseEv)
{}
