// weekview.cpp
#include "calendarutils.hpp"

using namespace CalendarUtils;

WeekView::WeekView(unsigned short maxWeekCount)
	: __maxWeekCount(maxWeekCount), CalendarView(7*maxWeekCount)
{
}
WeekView::WeekView(WeekView const &weekView)
	: __maxWeekCount(weekView.__maxWeekCount), CalendarView(weekView)
{
}
WeekView::WeekView()
	: __maxWeekCount(5), CalendarView(7*5)
{
}
WeekView::~WeekView()
{
}

unsigned short WeekView::getMaxWeekCount()
{
	return __maxWeekCount;
}
void WeekView::setMaxWeekCount(unsigned short count)
{
	__maxWeekCount = count;
	__daySlots = 7*count;
	if (&(((Calendar)__data)->getView()) == this)
		display();
}

void WeekView::onShow()
{
	CalendarView::onShow();
}
void WeekView::onHide()
{
	CalendarView::onHide();
}
void WeekView::display()
{
	CalendarView::display();
}

unsigned short WeekView::daySlots()
{
	return 7*__maxWeekCount;
}
unsigned short WeekView::dayCount()
{
	return daySlots();
}