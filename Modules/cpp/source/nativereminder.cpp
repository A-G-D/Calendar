// nativereminder.cpp
#include "nativecalendarapp.hpp"
#include <string>

using namespace NativeCalendarApp;
using namespace std;

#define __ NativeReminder


__::__(unsigned short hour, unsigned short minute, unsigned short second)
	: __hour(hour), __minute(minute), __second(second)
{
}
__::__(__ const &reminder)
	: __hour(reminder.__hour), __minute(reminder.__minute), __second(reminder.__second)
{
}
__::__()
{
}
__::~__()
{
}

unsigned short __::hour() const
{
	return __hour;
}
unsigned short __::minute() const
{
	return __minute;
}
unsigned short __::second() const
{
	return __second;
}
string &__::note()
{
	return __note;
}

string __::toString() const
{
	return to_string(__hour) + " : " + to_string(__minute) + " : " + to_string(__second);
}

void __::update(unsigned short hour, unsigned short minute, unsigned short second)
{
	__hour = hour;
	__minute = minute;
	__second = second;
}