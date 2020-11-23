#include "gauge.h"

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

void Gauge::fill(uint32_t value) {
	uint32_t estimated = _value + value;
	if ( (estimated < _value) || (estimated > _capacity) ){
		_value = _capacity;
	} else {
		_value += value;
	}
}
