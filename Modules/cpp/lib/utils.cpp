// utils.hpp
#include "calendarutils.hpp"

using namespace CalendarUtils;

unsigned short GetDateWeekPosition(Date *date)
{
	return ...;
}
unsigned short GetDateDayIndex(Date *date)
{
	unsigned short modulu(date->day()%7);
	if (!modulu)
		modulu = 7;
	return GetDateWeekPosition(date) + date.day() - modulu;
}
unsigned short GetMonthDayCount(Date *date)
{
	switch (date->month())
	{
		case 1:
			return 31;
		case 2:
			return (!(date->year()%4) || !(date->year()%100)) ? 29 : 28;
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
}
