#include "pokemon.h"

uint32_t Pokemon::computeStat(uint32_t baseStat, uint32_t iv, uint32_t ev, Level level, Coefficient coefficient) {
	uint32_t bonusEv = ev / 4u;
	uint32_t currentLevel = level._gauge.getValue();

	return ((((2u * baseStat + iv + bonusEv) * currentLevel) / 100u) + 5u) * coefficient._value;
}

uint32_t Pokemon::computeMaxHealth(uint32_t baseStat, uint32_t iv, uint32_t ev, Level level) {
	uint32_t bonusEv = ev / 4u;
	uint32_t currentLevel = level._gauge.getValue();

	return (((2u * baseStat + iv + bonusEv) * currentLevel) / 100u) + currentLevel + 10u;
}

Pokemon::Pokemon()
	: _name(), _specie(), _height(), _weight(),
	_health(), _level(), _experience(), _iv(), _ev(), _nature()
{}

Pokemon::Pokemon(PokemonCreateInfo infos)
	: _name(infos._name), _specie(infos._specie), _height(infos._height),
	_weight(infos._weight), _health(infos._health), _level(infos._level),
	_experience(infos._experience), _iv(infos._iv), _ev(infos._ev), _nature(infos._nature)
{}

uint32_t Pokemon::getAttack() const {
	uint32_t ivAttack = _iv._bonus._attack;
	uint32_t evAttack = _ev._attack.getValue();
	uint32_t baseAttack = _specie._baseStats._attack;
	Coefficient coefficientAttack = _nature._attack;

	return Pokemon::computeStat(baseAttack, ivAttack, evAttack, _level, coefficientAttack);
}

uint32_t Pokemon::getDefence() const {
	uint32_t ivDefence = _iv._bonus._defence;
	uint32_t evDefence = _ev._defence.getValue();
	uint32_t baseDefence = _specie._baseStats._defence;
	Coefficient coefficientDefence = _nature._defence;

	return Pokemon::computeStat(baseDefence, ivDefence, evDefence, _level, coefficientDefence);
}

uint32_t Pokemon::getAttackSpe() const {
	uint32_t ivAttackSpe = _iv._bonus._attackSpe;
	uint32_t evAttackSpe = _ev._attackSpe.getValue();
	uint32_t baseAttackSpe = _specie._baseStats._attackSpe;
	Coefficient coefficientAttackSpe = _nature._attackSpe;

	return Pokemon::computeStat(baseAttackSpe, ivAttackSpe, evAttackSpe, _level, coefficientAttackSpe);
}

uint32_t Pokemon::getDefenceSpe() const {
	uint32_t ivDefenceSpe = _iv._bonus._defenceSpe;
	uint32_t evDefenceSpe = _ev._defenceSpe.getValue();
	uint32_t baseDefenceSpe = _specie._baseStats._defenceSpe;
	Coefficient coefficientDefenceSpe = _nature._defenceSpe;

	return Pokemon::computeStat(baseDefenceSpe, ivDefenceSpe, evDefenceSpe, _level, coefficientDefenceSpe);
}

uint32_t Pokemon::getSpeed() const {
	uint32_t ivSpeed = _iv._bonus._speed;
	uint32_t evSpeed = _ev._speed.getValue();
	uint32_t baseSpeed = _specie._baseStats._speed;
	Coefficient coefficientSpeed = _nature._speed;

	return Pokemon::computeStat(baseSpeed, ivSpeed, evSpeed, _level, coefficientSpeed);
}

bool Pokemon::isExperienceEmpty() const {
	return _experience._gauge.isEmpty();
}

bool Pokemon::isExperienceFull() const {
	return _experience._gauge.isFull();
}

void Pokemon::setExperienceEmpty() {
	_experience._gauge.setEmpty();
}

void Pokemon::setExperienceFull() {
	_experience._gauge.setFull();
	this->addLevel(1u);
}

void Pokemon::addExperience(uint32_t value) {
	uint32_t gap = _experience._gauge.getCapacity() - _experience._gauge.getValue();
	_experience._gauge.add(value);

	if (_experience._gauge.isFull()) {
		this->addLevel(1u);
		this->addExperience(value - gap);
	}
}

void Pokemon::removeExperience(uint32_t value) {
	_experience._gauge.remove(value);
}

uint32_t Pokemon::getExperienceMax() const {
	_experience._gauge.getCapacity();
}

uint32_t Pokemon::getExperience() const {
	_experience._gauge.getValue();
}

void Pokemon::setExperience(uint32_t value) {
	_experience._gauge.setValue(value);
	
	if (_experience._gauge.isFull()) {
		this->addLevel(1u);
	}
}

bool Pokemon::isLevelEmpty() const {
	_level._gauge.isEmpty();
}

bool Pokemon::isLevelFull() const {
	_level._gauge.isFull();
}

void Pokemon::setLevelEmpty() {
	_level._gauge.setEmpty();
}

void Pokemon::setLevelFull() {
	_level._gauge.setFull();
}

void Pokemon::addLevel(uint32_t value) {
	_level._gauge.add(value);
	this->updateExperience();
	this->updateHealth();
}

void Pokemon::removeLevel(uint32_t value) {
	_level._gauge.remove(value);
	this->updateExperience();
	this->updateHealth();
}

uint32_t Pokemon::getLevelMax() const {
	_level._gauge.getCapacity();
}

uint32_t Pokemon::getLevel() const {
	_level._gauge.getValue();
}

void Pokemon::setLevel(uint32_t value) {
	_level._gauge.setValue(value);
	this->updateExperience();
	this->updateHealth();
}

void Pokemon::updateExperience() {
	uint32_t newExperienceMax = _specie._experienceCurve.getExperienceMax(_level._gauge.getValue());
	_experience = Experience(newExperienceMax);
}

void Pokemon::updateHealth() {
	uint32_t baseHealth = _specie._baseStats._health;
	uint32_t ivHealth = _iv._bonus._health;
	uint32_t evHealth = _ev._health.getValue();
	Health currentHealth = _health; 

	uint32_t newHealthMax = Pokemon::computeMaxHealth(baseHealth, ivHealth, evHealth, _level);
	float growthRatio = newHealthMax / currentHealth._gauge.getValue();
	uint32_t newHealthValue = currentHealth._gauge.getValue() * growthRatio;

	_health = Health(newHealthMax);
	_health._gauge.setValue(newHealthValue);
}