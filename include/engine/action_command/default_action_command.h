#ifndef DEFAULT_ACTION_COMMAND_H
#define DEFAULT_ACTION_COMMAND_H

#include "iaction_command.h"

class IDefaultActionCommand: public IActionCommand {
	public:
		inline void action() override{}
}

#endif
