#ifndef DEFAULT_EVENT_MAPPER_H
#define DEFAULT_EVENT_MAPPER_H

#include "ievent_mapper.h"
#include "ievent.h"
#include "iaction_command.h"

class DefaultEventMapper: public IEventMapper {
	public:

		@Override
		IActionCommand& getAction(const IEvent& event);

		@Override
		void setMap(const IEvent& event, const IActionCommand& action);
}

#endif
