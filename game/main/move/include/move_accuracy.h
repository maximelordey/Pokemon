#ifndef MOVE_ACCURACY_H
#define MOVE_ACCURACY_H

#include <cstdint>

class MoveAccuracy {
	public:
		MoveAccuracy();
		MoveAccuracy(uint32_t value);

	public:
		uint32_t _value;
};

#endif
