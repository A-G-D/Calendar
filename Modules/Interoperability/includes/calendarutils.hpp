/*
*	<calendarutils.hpp>
*/
#pragma once

#ifndef __CALENDARUTILS_HPP__
#define __CALENDARUTILS_HPP__

#include "calendarapp.hpp"

unsigned short GetDateWeekPosition(CalendarApp::Date ^date);
/*
*	Returns a value (0 - 6) corresponding to the position of the specific Date in the week
*	0 = Sunday; 6 = Saturday
*/
unsigned short GetDateDayIndex(CalendarApp::Date ^date);
/*
*	Index counts from 0 to 34 since the array size of the Dates of a month is 7*5 = 35
*/
unsigned short GetMonthDayCount(CalendarApp::Date ^date);
/*
*	Exactly what it says :D
*/

#endif

#pragma endregion