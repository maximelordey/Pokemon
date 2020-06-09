#ifndef IACTION_MANAGER_H
#define IACTION_MANAGER_H

#include "iaction_command.h"

class IActionManager {
	public:
		virtual bool hasEventPending() const = 0;
		virtual IActionCommand& getEventPending() = 0;
}
#endif