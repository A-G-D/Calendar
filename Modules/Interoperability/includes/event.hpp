/*
*	<calendarapp.hpp>
*
*
*	|-----|
*	| API |
*	|-----|
*
*	class Event
*
*		Event(Event const event)
*		Event()
*			- Constructors
*
*		void execute(void *v)
*			- Executes all registered callback functions
*
*		void registerHandler(callback h)
*			- Registers a function <h> to this Event
*			- The interface for callback functions is 'void FuncName(int i)'
*		void clearHandlers()
*			- Removes all registered callback functions
*/
#pragma once

#ifndef __EVENT_HPP__
#define __EVENT_HPP__

#include <nativeevent.hpp>

ref class Event
{
private:

	[System::Runtime::InteropServices::UnmanagedFunctionPointer(System::Runtime::InteropServices::CallingConvention::Cdecl)]
	delegate void callback(int i);

protected:

	!Event();

public:

	NativeEvent *__ptr;

	void execute(void *v);

	void registerHandler(callback ^h);
	void clearHandlers();

	Event(Event const ^event);
	Event();
	virtual ~Event();
};

#endif

#pragma endregion