// monthview.cpp
#include "calendarutils.hpp"

using namespace CalendarUtils;

MonthView::MonthView()
: CalendarView(35)
{
}
MonthView::MonthView(MonthView const &monthView)
: CalendarView(monthView)
{
}
MonthView::~MonthView()
{
}

MonthView::display()
{
	CalendarView::display();
}
