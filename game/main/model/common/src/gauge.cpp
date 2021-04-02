#include "gauge.h"

Gauge::Gauge()
: _capacity(0u), _value(0u)
{}

Gauge::Gauge(uint32_t capacity) 
: _capacity(capacity), _value(0u)
{}

bool Gauge::isEmpty() const {
	return _value == 0u;
}

bool Gauge::isFull() const {
	return _value == _capacity;
}

void Gauge::setEmpty() {
	_value = 0u;
}

void Gauge::setFull() {
	_value = _capacity;
}

void Gauge::add(uint32_t value) {
	uint32_t gap = _capacity - _value;
	if (value > gap){
		_value = _capacity;
	} else {
		_value += value;
	}
}

void Gauge::remove(uint32_t value) {
	if(_value < value) {
		_value = 0u;
	} else {
		_value -= value;
	}
}

uint32_t Gauge::getCapacity() const {
	return _capacity;
}

uint32_t Gauge::getValue() const {
	return _value;
}

uint32_t Gauge::getRemaining() const {
	return _capacity - _value;
}

void Gauge::setValue(uint32_t value) {
	if (value <= _capacity) {
		_value = value;
	}
}

Gauge Gauge::operator+(uint32_t value) {
	Gauge gauge = *this;
	gauge.add(value);
	return gauge;
}

Gauge Gauge::operator-(uint32_t value) {
	Gauge gauge = *this;
	gauge.remove(value);
	return gauge;
}

Gauge& Gauge::operator+=(uint32_t value) {
	this->add(value);
	return *this;
}

Gauge& Gauge::operator-=(uint32_t value) {
	this->remove(value);
	return *this;
}
