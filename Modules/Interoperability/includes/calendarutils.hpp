#pragma once

#ifndef __CALENDARUTILS_HPP__
#define __CALENDARUTILS_HPP__

#include "calendarapp.hpp"

unsigned short GetDateWeekPosition(CalendarApp::Date ^date);
unsigned short GetDateDayIndex(CalendarApp::Date ^date);
unsigned short GetMonthDayCount(CalendarApp::Date ^date);

#endif

#pragma endregion