// nativeweekview.cpp
#include "nativecalendarapp.hpp"

using namespace NativeCalendarApp;

#define __ NativeWeekView


__::__(unsigned short maxWeekCount)
	: __maxWeekCount(maxWeekCount), NativeCalendarView(7*maxWeekCount)
{
}
__::__(__ const &weekView)
	: __maxWeekCount(weekView.__maxWeekCount), NativeCalendarView(weekView)
{
}
__::__()
	: __maxWeekCount(5), NativeCalendarView(7*5)
{
}
__::~__()
{
}

unsigned short __::getMaxWeekCount()
{
	return __maxWeekCount;
}
void __::setMaxWeekCount(unsigned short count)
{
	__maxWeekCount = count;
	__daySlots = 7*count;
	if (&(((NativeCalendar*)__data)->getView()) == this)
		display();
}

void __::onShow()
{
	NativeCalendarView::onShow();
}
void __::onHide()
{
	NativeCalendarView::onHide();
}
void __::display()
{
	NativeCalendarView::display();
}

unsigned short __::daySlots() const
{
	return 7*__maxWeekCount;
}
unsigned short __::dayCount() const
{
	return daySlots();
}