#include "gauge.h"

Gauge::Gauge(uint32_t capacity) 
: _capacity(capacity), _value(0)
{}

Gauge::Gauge(uint32_t capacity, uint32_t value) 
: _capacity(capacity), _value(value)
{
	if (_value > _capacity) {
		_value = _capacity;
	}
}

Gauge::Gauge(const Gauge &gauge) {
	_value = gauge._value;
	_capacity = gauge._capacity;
}

Gauge::Gauge(Gauge &&gauge) {
	_value = gauge._value;
	_capacity = gauge._capacity;
}

bool Gauge::isEmpty() const {
	return _value == 0;
}

bool Gauge::isFull() const {
	return _value == _capacity;
}

void Gauge::setEmpty() {
	_value = 0;
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
		_value = 0;
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

void Gauge::setValue(uint32_t value) {
	if (value <= _capacity) {
		_value = value;
	}
}

void Gauge::init(uint32_t capacity, uint32_t value) {
	if (value <= capacity) {
		_value = value;
		_capacity = capacity;
	}
}

Gauge& Gauge::operator=(const Gauge &gauge) {
	if (this != &gauge) {
		_value = gauge._value;
		_capacity = gauge._capacity;
	}
}

Gauge& Gauge::operator=(Gauge &&gauge) {
	if (this != &gauge) {
		_value = gauge._value;
		_capacity = gauge._capacity;
	}
}
