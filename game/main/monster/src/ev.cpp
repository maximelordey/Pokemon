#include "ev.h"
#include <algorithm>

Ev::Ev()
	: _health(), _attack(), _defence(),
	 _attackSpe(), _defenceSpe(), _speed(), _total_limit()
{}

Ev::Ev(uint32_t total_limit, uint32_t stat_limit)
	: _health(stat_limit), _attack(stat_limit), _defence(stat_limit),
	 _attackSpe(stat_limit), _defenceSpe(stat_limit), _speed(stat_limit), _total_limit(total_limit)
{}

void Ev::setHealth(uint32_t value) {
	uint32_t total_left = _total_limit - this->getTotalStats();
	uint32_t value_left = std::min(value,  total_left);

	_health.add(value_left);
}

void Ev::setAttack(uint32_t value) {

}

void Ev::setDefence(uint32_t value) {

}

void Ev::setAttackSpe(uint32_t value) {

}

void Ev::setDefenceSPe(uint32_t value) {

}

void Ev::setSpeed(uint32_t value) {

}

uint32_t Ev::getHealth() const {
	return _health.getValue();
}

uint32_t Ev::getAttack() const {
	return _attack.getValue();
}

uint32_t Ev::getDefence() const {
	return _defence.getValue();
}

uint32_t Ev::getAttackSpe() const {
	return _attackSpe.getValue();
}

uint32_t Ev::getDefenceSpe() const {
	return _defenceSpe.getValue();
}

uint32_t Ev::getSpeed() const {
	return _speed.getValue();
}

uint32_t Ev::getTotalStats() const {
	return _health.getValue() +
			_attack.getValue() +
			_defence.getValue() +
			_attackSpe.getValue() +
			_defenceSpe.getValue() +
			_speed.getValue();
}

