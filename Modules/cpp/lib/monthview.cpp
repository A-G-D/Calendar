// monthview.cpp
#include "calendarutils.hpp"

using namespace CalendarUtils;

MonthView::MonthView(MonthView const &monthView)
	: CalendarView(monthView)
{
}
MonthView::MonthView()
	: CalendarView(35)
{
}
MonthView::~MonthView()
{
}

void MonthView::onShow()
{
	CalendarView::onShow();
}
void MonthView::onHide()
{
	CalendarView::onHide();
}
void MonthView::display()
{
	CalendarView::display();
}