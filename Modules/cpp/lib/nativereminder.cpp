// nativereminder.cpp
#include "nativecalendarapp.hpp"
#include <string>

using namespace NativeCalendarApp;
using namespace std;

NativeReminder::NativeReminder(unsigned short hour, unsigned short minute, unsigned short second)
	: __hour(hour), __minute(minute), __second(second)
{
}
NativeReminder::NativeReminder(NativeReminder const &reminder)
	: __hour(reminder.__hour), __minute(reminder.__minute), __second(reminder.__second)
{
}
NativeReminder::NativeReminder()
{
}
NativeReminder::~NativeReminder()
{
}

unsigned short NativeReminder::hour() const
{
	return __hour;
}
unsigned short NativeReminder::minute() const
{
	return __minute;
}
unsigned short NativeReminder::second() const
{
	return __second;
}
string &NativeReminder::note()
{
	return __note;
}

string NativeReminder::toString() const
{
	return to_string(__hour) + " : " + to_string(__minute) + " : " + to_string(__second);
}

void NativeReminder::update(unsigned short hour, unsigned short minute, unsigned short second)
{
	__hour = hour;
	__minute = minute;
	__second = second;
}