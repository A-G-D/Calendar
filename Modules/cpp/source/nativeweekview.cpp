// nativeweekview.cpp
#include "nativecalendarapp.hpp"

using namespace NativeCalendarApp;

NativeWeekView::NativeWeekView(unsigned short maxWeekCount)
	: __maxWeekCount(maxWeekCount), NativeCalendarView(7*maxWeekCount)
{
}
NativeWeekView::NativeWeekView(NativeWeekView const &weekView)
	: __maxWeekCount(weekView.__maxWeekCount), NativeCalendarView(weekView)
{
}
NativeWeekView::NativeWeekView()
	: __maxWeekCount(5), NativeCalendarView(7*5)
{
}
NativeWeekView::~NativeWeekView()
{
}

unsigned short NativeWeekView::getMaxWeekCount()
{
	return __maxWeekCount;
}
void NativeWeekView::setMaxWeekCount(unsigned short count)
{
	__maxWeekCount = count;
	__daySlots = 7*count;
	if (&(((NativeCalendar*)__data)->getView()) == this)
		display();
}

void NativeWeekView::onShow()
{
	NativeCalendarView::onShow();
}
void NativeWeekView::onHide()
{
	NativeCalendarView::onHide();
}
void NativeWeekView::display()
{
	NativeCalendarView::display();
}

unsigned short NativeWeekView::daySlots() const
{
	return 7*__maxWeekCount;
}
unsigned short NativeWeekView::dayCount() const
{
	return daySlots();
}
