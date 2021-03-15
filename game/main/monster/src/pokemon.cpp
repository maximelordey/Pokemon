#include "pokemon.h"

uint32_t Pokemon::getStat(uint32_t baseStat, uint32_t iv, uint32_t ev, Level level, Coefficient coefficient) {
	uint32_t bonusEv = ev / 4u;
	uint32_t currentLevel = level._gauge.getValue();

	return ((((2u * baseStat + iv + bonusEv) * currentLevel) / 100u) + 5u) * coefficient._value;
}

uint32_t Pokemon::getMaxHealth(uint32_t baseStat, uint32_t iv, uint32_t ev, Level level) {
	uint32_t bonusEv = ev / 4u;
	uint32_t currentLevel = level._gauge.getValue();

	return (((2u * baseStat + iv + bonusEv) * currentLevel) / 100u) + currentLevel + 10u;
}

Pokemon::Pokemon()
	: _identifier(), _name(), _specie(), _height(), _weight(),
	_health(), _level(), _experience(), _iv(), _ev(), _nature()
{}

Pokemon::Pokemon(PokemonCreateInfo infos)
	: _identifier(infos._identifier), _name(infos._name), _specie(infos._specie),
	_height(infos._height),_weight(infos._weight), _health(infos._health), _level(infos._level),
	_experience(infos._experience), _iv(infos._iv), _ev(infos._ev), _nature(infos._nature)
{}

uint32_t Pokemon::getAttack() const {
	uint32_t ivAttack = _iv._bonus._attack;
	uint32_t evAttack = _ev._attack.getValue();
	uint32_t baseAttack = _specie._baseStats._attack;
	Coefficient coefficientAttack = _nature._attack;

	return Pokemon::getStat(baseAttack, ivAttack, evAttack, _level, coefficientAttack);
}

uint32_t Pokemon::getDefence() const {
	uint32_t ivDefence = _iv._bonus._defence;
	uint32_t evDefence = _ev._defence.getValue();
	uint32_t baseDefence = _specie._baseStats._defence;
	Coefficient coefficientDefence = _nature._defence;

	return Pokemon::getStat(baseDefence, ivDefence, evDefence, _level, coefficientDefence);
}

uint32_t Pokemon::getAttackSpe() const {
	uint32_t ivAttackSpe = _iv._bonus._attackSpe;
	uint32_t evAttackSpe = _ev._attackSpe.getValue();
	uint32_t baseAttackSpe = _specie._baseStats._attackSpe;
	Coefficient coefficientAttackSpe = _nature._attackSpe;

	return Pokemon::getStat(baseAttackSpe, ivAttackSpe, evAttackSpe, _level, coefficientAttackSpe);
}

uint32_t Pokemon::getDefenceSpe() const {
	uint32_t ivDefenceSpe = _iv._bonus._defenceSpe;
	uint32_t evDefenceSpe = _ev._defenceSpe.getValue();
	uint32_t baseDefenceSpe = _specie._baseStats._defenceSpe;
	Coefficient coefficientDefenceSpe = _nature._defenceSpe;

	return Pokemon::getStat(baseDefenceSpe, ivDefenceSpe, evDefenceSpe, _level, coefficientDefenceSpe);
}

uint32_t Pokemon::getSpeed() const {
	uint32_t ivSpeed = _iv._bonus._speed;
	uint32_t evSpeed = _ev._speed.getValue();
	uint32_t baseSpeed = _specie._baseStats._speed;
	Coefficient coefficientSpeed = _nature._speed;

	return Pokemon::getStat(baseSpeed, ivSpeed, evSpeed, _level, coefficientSpeed);
}
