#include "move_accuracy.h"

const uint8_t MoveAccuracy::DEFAULT_VALUE = UINT8_MAX;

MoveAccuracy::MoveAccuracy()
	: _value(DEFAULT_VALUE)
{}

MoveAccuracy::MoveAccuracy(float value)
	: _value(value)
{}