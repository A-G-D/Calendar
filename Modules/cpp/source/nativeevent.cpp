// nativeevent.cpp
#include "nativeevent.hpp"

#define __ NativeEvent


__::__(__ const &event)
	: __handlers(event.__handlers)
{
}
__::__()
{
}
__::~__()
{
}

void __::execute(void *v = 0)
{
	for(handler h : __handlers) h(v);
}

void __::registerHandler(handler h)
{
	__handlers.push_back(h);
}
void __::clearHandlers()
{
	__handlers.clear();
}