#include "gauge.h"

bool Gauge::isEmpty() {
	return _value == 0;
}

bool Gauge::isFull() {
	return _value == _capacity;
}