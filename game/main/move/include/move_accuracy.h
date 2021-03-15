#ifndef MOVE_ACCURACY_H
#define MOVE_ACCURACY_H

#include <cstdint>

class MoveAccuracy {
	private:
		static const uint8_t DEFAULT_VALUE;

	public:
		MoveAccuracy();
		MoveAccuracy(float value, bool cannotMiss);

	public:
		uint8_t _value;
		bool _cannotMiss;
};

#endif
