#include "gauge.h"

bool Gauge::isEmpty() const {
	return _value == 0;
}

bool Gauge::isFull() const {
	return _value == _capacity;
}