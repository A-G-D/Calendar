#include "calendarapp.hpp"

using namespace CalendarApp;

unsigned short WeekView::getMaxWeekCount()
{
	return __ptr->getMaxWeekCount();
}
void WeekView::setMaxWeekCount(unsigned short count)
{
	__ptr->setMaxWeekCount(count);
}

unsigned short WeekView::daySlots()
{
	return __ptr->daySlots();
}
unsigned short WeekView::dayCount()
{
	return __ptr->dayCount();
}

void WeekView::display()
{
	__ptr->display();
}

WeekView::WeekView(unsigned short maxWeekCount)
	: __ptr(new NativeWeekView(maxWeekCount))
{
}
WeekView::WeekView(WeekView const ^weekView)
	: __ptr(new NativeWeekView(*(weekView->__ptr)))
{
}
WeekView::WeekView()
	: __ptr(new NativeWeekView)
{
}
WeekView::~WeekView()
{
	this->!WeekView();
}
WeekView::!WeekView()
{
	delete __ptr;
}