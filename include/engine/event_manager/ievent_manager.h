#ifndef IEVENT_MANAGER_H
#define IEVENT_MANAGER_H

class IEventManager {
	public:
		virtual bool hasEventPending() const = 0;
		virtual const IEvent getEventPending() const = 0;
}

#endif
