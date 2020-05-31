class IActionManager {
	public:
		virtual bool hasEventPending() = 0;
		virtual IActionCommand getEventPending() = 0;
}
