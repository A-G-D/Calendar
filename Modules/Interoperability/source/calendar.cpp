#include "calendarapp.hpp"

using namespace CalendarApp;

void Calendar::goToDate(Date ^date)
{
	__ptr->goToDate(*(date->__ptr));
}

CalendarView ^Calendar::getView()
{
	return gcnew CalendarView(__ptr->getView());
}
CalendarViewType Calendar::getViewType()
{
	return static_cast<CalendarViewType>(__ptr->getViewType());
}
void Calendar::setViewType(CalendarViewType viewType)
{
	__ptr->setViewType(static_cast<NativeCalendarViewType>(viewType));
}

Calendar::Calendar(CalendarViewType viewType)
	: __ptr(new NativeCalendar(static_cast<NativeCalendarViewType>(viewType)))
{
}
Calendar::Calendar(Calendar const ^calendar)
	: __ptr(new NativeCalendar(*(calendar->__ptr)))
{
}
Calendar::Calendar()
	: __ptr(new NativeCalendar)
{
}
Calendar::~Calendar()
{
	this->!Calendar();
}
Calendar::!Calendar()
{
	delete __ptr;
}