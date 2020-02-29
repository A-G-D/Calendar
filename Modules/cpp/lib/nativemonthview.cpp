// nativemonthview.cpp
#include "nativecalendarapp.hpp"

using namespace NativeCalendarApp;

NativeMonthView::NativeMonthView(NativeMonthView const &monthView)
	: NativeCalendarView(monthView)
{
}
NativeMonthView::NativeMonthView()
	: NativeCalendarView(35)
{
}
NativeMonthView::~NativeMonthView()
{
}

void NativeMonthView::onShow()
{
	NativeCalendarView::onShow();
}
void NativeMonthView::onHide()
{
	NativeCalendarView::onHide();
}
void NativeMonthView::display()
{
	NativeCalendarView::display();
}