#include "calendarapp.hpp"

using namespace CalendarApp;

void MonthView::display()
{
	__ptr->display();
}

MonthView::MonthView(MonthView const ^monthView)
	: __ptr(new NativeMonthView(*(monthView->__ptr)))
{
}
MonthView::MonthView()
	: __ptr(new NativeMonthView)
{
}
MonthView::~MonthView()
{
	this->!MonthView();
}
MonthView::!MonthView()
{
	delete __ptr;
}