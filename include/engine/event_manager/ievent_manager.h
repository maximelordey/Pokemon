class IEventManager {
	public:
		virtual bool hasEventPending() = 0;
		virtual IEvent getEventPending() = 0;
}
