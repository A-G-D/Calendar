#include "calendarapp.hpp"

using namespace CalendarApp;

unsigned short Reminder::hour()
{
	return __ptr->hour();
}
unsigned short Reminder::minute()
{
	return __ptr->minute();
}
unsigned short Reminder::second()
{
	return __ptr->second();
}
String ^Reminder::note()
{
	return gcnew String(__ptr->note().data());
}

String ^Reminder::toString()
{
	return gcnew String(__ptr->toString().data());
}

void Reminder::update(unsigned short hour, unsigned short minute, unsigned short second)
{
	__ptr->update(hour, minute, second);
}

Reminder::Reminder(unsigned short hour, unsigned short minute, unsigned short second)
	: __ptr(new NativeReminder(hour, minute, second))
{
}
Reminder::Reminder(Reminder const ^reminder)
	: __ptr(new NativeReminder(*(reminder->__ptr)))
{
}
Reminder::~Reminder()
{
	this->!Reminder();
}
Reminder::!Reminder()
{
	delete __ptr;
}