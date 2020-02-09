// weekview.cpp
#include "calendarutils.hpp"

using namespace CalendarUtils;

WeekView::WeekView()
: CalendarView(7)
{
}
WeekView::WeekView(WeekView const &weekView)
: CalendarView(weekView)
{
}
WeekView::~WeekView()
{
}

WeekView::display()
{
	CalendarView::display();
}
