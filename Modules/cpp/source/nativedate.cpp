// nativedate.cpp
#include "nativecalendarapp.hpp"
#include <ctime>
#include <vector>

using namespace NativeCalendarApp;
using namespace std;

void LoadReminders(NativeDate const &date)
{
	
}

//*********************************************************

NativeDate::NativeDate(int year, unsigned short month, unsigned short day)
	: __year(year), __month(month), __day(day), __reminders(new vector<NativeReminder>)
{
	LoadReminders(*this);
}
NativeDate::NativeDate(NativeDate const &date)
	: __year(date.__year), __month(date.__month), __day(date.__day), __reminders(date.__reminders)
{
	LoadReminders(*this);
}
NativeDate::NativeDate()
{
}
NativeDate::~NativeDate()
{
	clearReminders();
}

NativeDate const &NativeDate::today()
{
	time_t now(time(0));
	tm *pdate(localtime(&now));
	return NativeDate(pdate->tm_year + 1900, pdate->tm_mon, pdate->tm_mday);
}

unsigned short NativeDate::day() const
{
	return __day;
}
unsigned short NativeDate::month() const
{
	return __month;
}
int NativeDate::year() const
{
	return __year;
}

bool NativeDate::operator==(NativeDate const &date)
{
	return __year == date.__year && __month == date.__month && __day == date.__day;
}
bool NativeDate::operator!=(NativeDate const &date)
{
	return !(*this == date);
}
bool NativeDate::operator<(NativeDate const &date)
{
	if (__year < date.__year)
		return true;
	else if (__year > date.__year)
		return false;
	else if (__month < date.__year)
		return true;
	else if (__month < date.__month)
		return false;
	else if (__day < date.__day)
		return true;
	else if (__day > date.__day)
		return false;
	return false;
}
bool NativeDate::operator>(NativeDate const &date)
{
	return *this != date && !(*this < date);
}
bool NativeDate::operator<=(NativeDate const &date)
{
	return *this == date || *this < date;
}
bool NativeDate::operator>=(NativeDate const &date)
{
	return *this == date || *this > date;
}

vector<NativeReminder> NativeDate::getReminders()
{
	return *__reminders;
}

void NativeDate::addReminder(NativeReminder const &reminder)
{
	__reminders->push_back(reminder);
}
void NativeDate::clearReminders()
{
	__reminders->clear();
}
