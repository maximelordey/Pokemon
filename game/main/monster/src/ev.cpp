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

bool Ev::isHealthEmpty() const {
	return _health.isEmpty();
}

bool Ev::isHealthFull() const {
	return _health.isFull();
}

void Ev::setHealthEmpty() {
	return _health.setEmpty();
}

void Ev::setHealthFull() {

}

void Ev::addHealth(uint32_t value) {
	uint32_t total_gap = _total_limit - this->getTotalStats();
	uint32_t final_value = std::min(value, total_gap);
	_health.add(final_value);
}

void Ev::removeHealth(uint32_t value) {
	_health.remove(value);
}

uint32_t Ev::getHealthCapacity() const {
	return _health.getCapacity();
}

uint32_t Ev::getHealthValue() const {
	return _health.getValue();
}

void Ev::setHealthValue(uint32_t value) {
	uint32_t total_without_health = this->getTotalStats() - _health.getValue();
	uint32_t total_gap = _total_limit - total_without_health;
	uint32_t final_value = std::min(value, total_gap);
	_health.setValue(final_value);
}

void Ev::initHealth(uint32_t capacity, uint32_t value) {
	_health.init(capacity, value);
}


bool Ev::isAttackEmpty() const {
	return _attack.isEmpty();
}

bool Ev::isAttackFull() const {
	return _attack.isFull();
}

void Ev::setAttackEmpty() {
	_attack.setEmpty();
}

void Ev::setAttackFull() {

}

void Ev::addAttack(uint32_t value) {
	uint32_t total_gap = _total_limit - this->getTotalStats();
	uint32_t final_value = std::min(value, total_gap);
	_attack.add(final_value);
}

void Ev::removeAttack(uint32_t value) {
	_attack.remove(value);
}

uint32_t Ev::getAttackCapacity() const {
	return _attack.getCapacity();
}

uint32_t Ev::getAttackValue() const {
	return _attack.getValue();
}

void Ev::setAttackValue(uint32_t value) {
	uint32_t total_without_attack = this->getTotalStats() - _attack.getValue();
	uint32_t total_gap = _total_limit - total_without_attack;
	uint32_t final_value = std::min(value, total_gap);
	_attack.setValue(final_value);
}

void Ev::initAttack(uint32_t capacity, uint32_t value) {
	_attack.init(capacity, value);
}


bool Ev::isDefenceEmpty() const {
	return _defence.isEmpty();
}

bool Ev::isDefenceFull() const {
	return _defence.isFull();
}

void Ev::setDefenceEmpty() {
	_defence.setEmpty();
}

void Ev::setDefenceFull() {

}

void Ev::addDefence(uint32_t value) {
	uint32_t total_gap = _total_limit - this->getTotalStats();
	uint32_t final_value = std::min(value, total_gap);
	_defence.add(final_value);
}

void Ev::removeDefence(uint32_t value) {
	_defence.remove(value);
}

uint32_t Ev::getDefenceCapacity() const {
	return _defence.getCapacity();
}

uint32_t Ev::getDefenceValue() const {
	return _defence.getValue();
}

void Ev::setDefenceValue(uint32_t value) {
	uint32_t total_without_defence = this->getTotalStats() - _defence.getValue();
	uint32_t total_gap = _total_limit - total_without_defence;
	uint32_t final_value = std::min(value, total_gap);
	_attack.setValue(final_value);
}

void Ev::initDefence(uint32_t capacity, uint32_t value) {
	_defence.init(capacity, value);
}


bool Ev::isAttackSpeEmpty() const {
	return _attackSpe.isEmpty();
}

bool Ev::isAttackSpeFull() const {
	return _attackSpe.isFull();
}

void Ev::setAttackSpeEmpty() {
	_attackSpe.setEmpty();
}

void Ev::setAttackSpeFull() {

}

void Ev::addAttackSpe(uint32_t value) {
	uint32_t total_gap = _total_limit - this->getTotalStats();
	uint32_t final_value = std::min(value, total_gap);
	_attackSpe.add(final_value);
}

void Ev::removeAttackSpe(uint32_t value) {
	_attackSpe.remove(value);
}

uint32_t Ev::getAttackSpeCapacity() const {
	return _attackSpe.getCapacity();
}

uint32_t Ev::getAttackSpeValue() const {
	return _attackSpe.getValue();
}

void Ev::setAttackSpeValue(uint32_t value) {
	uint32_t total_without_attackSpe = this->getTotalStats() - _attackSpe.getValue();
	uint32_t total_gap = _total_limit - total_without_attackSpe;
	uint32_t final_value = std::min(value, total_gap);
	_attack.setValue(final_value);
}

void Ev::initAttackSpe(uint32_t capacity, uint32_t value) {
	_attackSpe.init(capacity, value);
}


bool Ev::isDefenceSpeEmpty() const {
	return _defenceSpe.isEmpty();
}

bool Ev::isDefenceSpeFull() const {
	return _defenceSpe.isFull();
}

void Ev::setDefenceSpeEmpty() {
	_defenceSpe.setEmpty();
}

void Ev::setDefenceSpeFull() {

}

void Ev::addDefenceSpe(uint32_t value) {
	uint32_t total_gap = _total_limit - this->getTotalStats();
	uint32_t final_value = std::min(value, total_gap);
	_defenceSpe.add(final_value);
}

void Ev::removeDefenceSpe(uint32_t value) {
	_defenceSpe.remove(value);
}

uint32_t Ev::getDefenceSpeCapacity() const {
	return _defenceSpe.getCapacity();
}

uint32_t Ev::getDefenceSpeValue() const {
	return _defenceSpe.getValue();
}

void Ev::setDefenceSpeValue(uint32_t value) {
	uint32_t total_without_defenceSpe = this->getTotalStats() - _defenceSpe.getValue();
	uint32_t total_gap = _total_limit - total_without_defenceSpe;
	uint32_t final_value = std::min(value, total_gap);
	_attack.setValue(final_value);
}

void Ev::initDefenceSpe(uint32_t capacity, uint32_t value) {
	_defenceSpe.init(capacity, value);
}


bool Ev::isSpeedEmpty() const {
	_speed.isEmpty();
}

bool Ev::isSpeedFull() const {
	_speed.isFull();
}

void Ev::setSpeedEmpty() {
	_speed.setEmpty();
}

void Ev::setSpeedFull() {

}

void Ev::addSpeed(uint32_t value) {
	uint32_t total_gap = _total_limit - this->getTotalStats();
	uint32_t final_value = std::min(value, total_gap);
	_speed.add(final_value);
}

void Ev::removeSpeed(uint32_t value) {
	_speed.remove(value);
}

uint32_t Ev::getSpeedCapacity() const {
	return _speed.getCapacity();
}

uint32_t Ev::getSpeedValue() const {
	return _speed.getValue();
}

void Ev::setSpeedValue(uint32_t value) {
	uint32_t total_without_speed = this->getTotalStats() - _speed.getValue();
	uint32_t total_gap = _total_limit - total_without_speed;
	uint32_t final_value = std::min(value, total_gap);
	_attack.setValue(final_value);
}

void Ev::initSpeed(uint32_t capacity, uint32_t value) {
	_speed.init(capacity, value);
}


bool Ev::isFull() {
	return this->getTotalStats() == _total_limit;
}

uint32_t Ev::getTotalStats() const {
	return _health.getValue() +
			_attack.getValue() +
			_defence.getValue() +
			_attackSpe.getValue() +
			_defenceSpe.getValue() +
			_speed.getValue();
}

