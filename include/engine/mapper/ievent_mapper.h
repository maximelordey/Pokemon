#ifndef IEVENT_MAPPER_H
#define IEVENT_MAPPER_H

include "ievent.h"
include "iaction_command.h"

class IEventMapper {
	public:
		virtual IActionCommand& getAction(const IEvent event) = 0;
		virtual void addPair(const IEvent &event, const IActionCommand &action) = 0;
}

#endif
