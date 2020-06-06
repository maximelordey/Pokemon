#ifndef IACTION_COMMAND_H
#define IACTION_COMMAND_H

#include <cstdint>

class IActionCommand {
	public:
		virtual int32_t action() = 0;
}

#endif
