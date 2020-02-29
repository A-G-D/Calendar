#include "calendarapp.hpp"

using namespace CalendarApp;

unsigned short CalendarView::daySlots()
{
	return __ptr->daySlots();
}
unsigned short CalendarView::dayCount()
{
	return __ptr->dayCount();
}

void CalendarView::display()
{
	__ptr->display();
}
void CalendarView::createFromDate(Date ^date)
{
	__ptr->createFromDate(*(date->__ptr));
}

CalendarView::CalendarView(NativeCalendarView const &nativeCalendarView)
	: __ptr(const_cast<NativeCalendarView*>(&nativeCalendarView))
{
}
CalendarView::CalendarView(unsigned short dayCount)
	: __ptr(new NativeCalendarView(dayCount))
{
}
CalendarView::CalendarView(CalendarView const ^calendarView)
	: __ptr(new NativeCalendarView(*(calendarView->__ptr)))
{
}
CalendarView::~CalendarView()
{
	this->!CalendarView();
}
CalendarView::!CalendarView()
{
	delete __ptr;
}