#pragma once

#ifndef __UTILS_HPP__
#define __UTILS_HPP__

#include "nativecalendarapp.hpp"

unsigned short GetDateWeekPosition(NativeCalendarApp::NativeDate const &date);
unsigned short GetDateDayIndex(NativeCalendarApp::NativeDate const &date);
unsigned short GetMonthDayCount(NativeCalendarApp::NativeDate const &date);

#endif

#pragma endregion