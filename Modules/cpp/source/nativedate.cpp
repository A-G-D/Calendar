// nativedate.cpp
#include "nativecalendarapp.hpp"
#include <ctime>
#include <vector>

using namespace NativeCalendarApp;
using namespace std;

#define __ NativeDate


unsigned short __GetCenturyCode(__ const &date)
{
	return (__(1752, 8, 14) > date) ?
		(18 - (date.year()%1000 - date.year()%100))%7 : (3 - (date.year()/100)%4)*2;
}
unsigned short __GetMonthCode(unsigned short month)
{
	static unsigned short mcode[12] {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};
	return mcode[month];
}
void __LoadReminders(__ const &date)
{
	
}

//*********************************************************

__::__(int year, unsigned short month, unsigned short day)
	: __year(year), __month(month), __day(day), __reminders(new vector<NativeReminder>)
{
	__LoadReminders(*this);
}
__::__(__ const &date)
	: __year(date.__year), __month(date.__month), __day(date.__day), __reminders(date.__reminders)
{
	__LoadReminders(*this);
}
__::__()
{
}
__::~__()
{
	clearReminders();
}

__ const &__::today()
{
	time_t now(time(0));
	tm *pdate(localtime(&now));
	return __(pdate->tm_year + 1900, pdate->tm_mon, pdate->tm_mday);
}

unsigned short __::day() const
{
	return __day;
}
unsigned short __::month() const
{
	return __month;
}
int __::year() const
{
	return __year;
}

bool __::isLeapYear() const
{
	return (__(1752, 8, 14) > *this) ?
		year()%4 : (!(year()%4) || !(year()%400)) && !(year()%100);
}

int __::getDistance(__ const &date)
{
	int dy(date.year() - year());
	short
		dm(date.month() - month()),
		dd(date.day() - day());
	return dy*365 + dm*30 + dd; // to be continued
}
unsigned short __::getWeekPosition()
{
	unsigned short
		yy(year()%100),
		century_code(__GetCenturyCode(*this)),
		year_code((yy + (unsigned short)(yy/4))%7),
		month_code(__GetMonthCode(month()));
	return (century_code + year_code + month_code + day() - isLeapYear())%7; // Reference: https://artofmemory.com/blog/how-to-calculate-the-day-of-the-week-4203.html
}
unsigned short __::getDayIndex()
{
	unsigned short
		modulu(day()%7),
		weekPosition(getWeekPosition());
	if (!modulu && weekPosition == 6)
		modulu = 7;
	return weekPosition + day() - modulu;
}
unsigned short __::getMonthDayCount()
{
	switch (month())
	{
		case 1:
			return 31;
		case 2:
			return isLeapYear() ? 29 : 28;
		case 3:
			return 31;
		case 4:
			return 30;
		case 5:
			return 31;
		case 6:
			return 30;
		case 7:
			return 31;
		case 8:
			return 31;
		case 9:
			return 30;
		case 10:
			return 31;
		case 11:
			return 30;
		case 12:
			return 31;
	}
	return 0;
}

bool __::operator==(__ const &date)
{
	return __year == date.__year && __month == date.__month && __day == date.__day;
}
bool __::operator!=(__ const &date)
{
	return !(*this == date);
}
bool __::operator<(__ const &date)
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
bool __::operator>(__ const &date)
{
	return *this != date && !(*this < date);
}
bool __::operator<=(__ const &date)
{
	return *this == date || *this < date;
}
bool __::operator>=(__ const &date)
{
	return *this == date || *this > date;
}

vector<NativeReminder> __::getReminders()
{
	return *__reminders;
}

void __::addReminder(NativeReminder const &reminder)
{
	__reminders->push_back(reminder);
}
void __::clearReminders()
{
	__reminders->clear();
}