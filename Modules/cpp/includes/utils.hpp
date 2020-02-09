#pragma once

#ifndef __UTILS_HPP__
#define __UTILS_HPP__

class CalendarUtils::Date;

unsigned short GetDateWeekPosition(CalendarUtils::Date *date);
unsigned short GetDateDayIndex(CalendarUtils::Date *date);
unsigned short GetMonthDayCOunt(unsigned short month);

#endif

#pragma endregion
