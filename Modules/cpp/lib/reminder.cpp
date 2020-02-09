// reminder.cpp
#include "calendarutils.hpp"
#include <string>

using namespace CalendarUtils;
using namespace std;

Reminder::Reminder(unsigned int hour, unsigned int minute, unsigned int second)
: __hour(hour), __minute(minute), __second(second)
{
}
Reminder::Reminder(Reminder const &reminder)
: __hour(reminder.__hour), __minute(reminder.__minute), __second(reminder.__second)
{
}
Reminder::Reminder()
{
}
Reminder::~Reminder()
{
}

unsigned short Reminder::hour()
{
	return __hour;
}
unsigned short Reminder::minute()
{
	return __minute;
}
unsigned short Reminder::second()
{
	return __second;
}
string &Reminder::toString()
{
	return to_string(__hour) + " : " + to_string(__minute) + " : " + to_string(__second);
}

void Reminder::update(unsigned short hour, unsigned short minute, unsigned short second)
{
	__hour = hour;
	__minute = minute;
	__second = second;
}
