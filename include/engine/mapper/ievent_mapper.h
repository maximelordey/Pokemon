class IEventMapper {
	public:
		virtual IActionCommand getAction(IEvent event) = 0;
		virtual void addPair(IEvent event, IActionCommand action) = 0;
}
