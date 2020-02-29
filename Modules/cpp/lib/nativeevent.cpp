// nativeevent.cpp
#include "nativeevent.hpp"

NativeEvent::NativeEvent(NativeEvent const &event)
	: __handlers(event.__handlers)
{
}
NativeEvent::NativeEvent()
{
}
NativeEvent::~NativeEvent()
{
}

void NativeEvent::execute(void *v = 0)
{
	for(handler h : __handlers) h(v);
}

void NativeEvent::registerHandler(handler h)
{
	__handlers.push_back(h);
}
void NativeEvent::clearHandlers()
{
	__handlers.clear();
}