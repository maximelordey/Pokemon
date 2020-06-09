#ifndef IACTION_COMMAND_H
#define IACTION_COMMAND_H

#include <cstdint>

class IActionCommand {
	public:
		virtual void action() = 0;
}

#endif
