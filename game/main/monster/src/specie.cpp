#include "specie.h"

Specie::Specie(const SpecieCreateInfo& info)
	: _name(info.pName), _types(info.typeCount, info.pTypes), _size(info.size),
	_weight(info.weight), _baseHealth(info.baseHealth), _baseAttack(info.baseAttack),
	_baseDefence(info.baseDefence), _baseAttackSpe(info.baseAttackSpe),
	_baseDefenceSpe(info.baseDefenceSpe), _baseSpeed(info.baseSpeed),
	_experienceCurve(info.pExperienceCurve)
{}