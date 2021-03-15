#include "move_accuracy.h"

const uint8_t MoveAccuracy::DEFAULT_VALUE = UINT8_MAX;

MoveAccuracy::MoveAccuracy()
	: _value(DEFAULT_VALUE), _cannotMiss(false)
{}

MoveAccuracy::MoveAccuracy(float value, bool canMiss)
	: _value(value), _cannotMiss(canMiss)
{}