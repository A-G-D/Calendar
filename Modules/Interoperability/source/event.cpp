#include "event.hpp"
#include "namespaces.hpp"

void Event::execute(void *v)
{
	__ptr->execute(v);
}

void Event::registerHandler(callback ^h)
{
	typedef void (*handler)(void*);
	__ptr->registerHandler((handler)(Marshal::GetFunctionPointerForDelegate(h).ToPointer()));
}
void Event::clearHandlers()
{
	__ptr->clearHandlers();
}

Event::Event(Event const ^event)
	: __ptr(new NativeEvent(*(event->__ptr)))
{
}
Event::Event()
	: __ptr(new NativeEvent)
{
}
Event::~Event()
{
	this->!Event();
}
Event::!Event()
{
	delete __ptr;
}