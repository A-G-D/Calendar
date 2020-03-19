#pragma once

#ifndef __NATIVEEVENT_HPP__
#define __NATIVEEVENT_HPP__

#include <list>


class NativeEvent
{
private:

	typedef void (*handler)(void*);
	std::list<handler> __handlers;

public:

	void execute(void *v);

	void registerHandler(handler h);
	void clearHandlers();

	NativeEvent(NativeEvent const &event);
	NativeEvent();
	virtual ~NativeEvent();
};

#endif

#pragma endregion