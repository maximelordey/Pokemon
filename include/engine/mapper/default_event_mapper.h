#ifndef DEFAULT_EVENT_MAPPER_H
#define DEFAULT_EVENT_MAPPER_H

#include "ievent_mapper.h"
#include "ievent.h"
#include "iaction_command.h"

class DefaultEventMapper: public IEventMapper {
	public:
		IActionCommand& toAction(const IEvent& event) override;

		void setMap(const IEvent& event, const IActionCommand& action) override;
}

#endif