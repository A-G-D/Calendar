// nativecalendarutils.cpp
#include "nativecalendarapp.hpp"

using namespace NativeCalendarApp;

unsigned short GetDateWeekPosition(NativeDate const &date)
{
	return 0;//...
}
unsigned short GetDateDayIndex(NativeDate const &date)
{
	unsigned short
		modulu(date.day()%7),
		weekPosition(GetDateWeekPosition(date));
	if (!modulu && weekPosition == 6)
		modulu = 7;
	return weekPosition + date.day() - modulu;
}
unsigned short GetMonthDayCount(NativeDate const &date)
{
	switch (date.month())
	{
		case 1:
			return 31;
		case 2:
			return ((!(date.year()%4) || !(date.year()%400)) && !(date.year()%100)) ? 29 : 28;
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
