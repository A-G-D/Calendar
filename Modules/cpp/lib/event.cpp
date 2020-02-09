// event.cpp
#include "event.hpp"

Event::Event()
{
}
Event::~Event()
{
}

void Event::execute(void *v = 0)
{
	for(handler h : __handlers) h(v);
}

void Event::registerHandler(handler h)
{
	__handlers.push_back(h);
}
void Event::clearHandlers()
{
	__handlers.clear();
}
