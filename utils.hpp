#pragma once

#ifndef __UTILS_HPP__
#define __UTILS_HPP__

#include "calendarutils.hpp"

unsigned short GetDateWeekPosition(CalendarUtils::Date *date);
unsigned short GetDateDayIndex(CalendarUtils::Date *date);
unsigned short GetMonthDayCount(CalendarUtils::Date *date);

#endif

#pragma endregion