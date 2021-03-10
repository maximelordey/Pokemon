#include "specie.h"

Specie::Specie(const SpecieCreateInfo& info)
	: _identifier(info._identifier), _name(info._names), _types(info._types),
	_experienceCurve(info._pExperienceCurve), _height(info._Height),
	_weight(info._Weight), _baseStats(info._BaseStats), _baseEv(info._BaseEv)
{}
