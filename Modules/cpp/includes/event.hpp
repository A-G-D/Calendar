#pragma once

#ifndef __EVENT_HPP__
#define __EVENT_HPP__

#include <list>

using namespace std;

class Event
{
private:

	typedef void (*handler)(void*);
	list<handler> __handlers;

public:

	void execute(void *v);

	void registerHandler(handler h);
	void clearHandlers();

	Event();
	~Event();
};

#endif

#pragma endregion
