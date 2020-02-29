#include "calendarutils.hpp"
#include <nativecalendarutils.hpp>

unsigned short GetDateWeekPosition(CalendarApp::Date ^date)
{
	return GetDateWeekPosition(*(date->__ptr));
}
unsigned short GetDateDayIndex(CalendarApp::Date ^date)
{
	return GetDateDayIndex(*(date->__ptr));
}
unsigned short GetMonthDayCount(CalendarApp::Date ^date)
{
	return GetMonthDayCount(*(date->__ptr));
}