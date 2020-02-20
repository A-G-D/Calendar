// date.cpp
#include "calendarutils.hpp"
#include <ctime>
#include <vector>

using namespace CalendarUtils;
using namespace std;

void LoadReminders(Date const &date)
{
	
}

//*********************************************************

Date::Date(int year, unsigned short month, unsigned short day)
	: __year(year), __month(month), __day(day), __reminders(new vector<Reminder>)
{
	LoadReminders(*this);
}
Date::Date(Date const &date)
	: __year(date.__year), __month(date.__month), __day(date.__day), __reminders(date.__reminders)
{
	LoadReminders(*this);
}
Date::Date()
{
}
Date::~Date()
{
	clearReminders();
}

Date const &Date::today()
{
	time_t now(time(0));
	tm *pdate(localtime(&now));
	return Date(pdate->tm_year + 1900, pdate->tm_mon, pdate->tm_mday);
}

bool Date::operator==(Date const &date)
{
	return __year == date.__year && __month == date.__month && __day == date.__day;
}
bool Date::operator!=(Date const &date)
{
	return !(*this == date);
}
bool Date::operator<(Date const &date)
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
bool Date::operator>(Date const &date)
{
	return *this != date && !(*this < date);
}
bool Date::operator<=(Date const &date)
{
	return *this == date || *this < date;
}
bool Date::operator>=(Date const &date)
{
	return *this == date || *this > date;
}

vector<Reminder> Date::getReminders()
{
	return *__reminders;
}

void Date::addReminder(Reminder const &reminder)
{
	__reminders->push_back(reminder);
}
void Date::clearReminders()
{
	__reminders->clear();
}