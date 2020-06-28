#ifndef IEVENT_MANAGER_H
#define IEVENT_MANAGER_H

#include "ievent.h"

class IEventManager {
	public:
		virtual bool hasEventPending() const = 0;
		virtual IEvent& getEventPending() const = 0;
};
#endif
