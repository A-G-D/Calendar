// calendarview.cpp
#include "calendarutils.hpp"
#include "utils.hpp"
#include "event.hpp"
#include <algorithm>

using namespace CalendarUtils;
using namespace std;

CalendarView::CalendarView(unsigned short daySlots)
	: __daySlots(daySlots), __days(static_cast<Date*>(::operator new(sizeof(Date)*daySlots))), onDisplay(new Event)
{
}
CalendarView::CalendarView(CalendarView const &calendarView)
	: __daySlots(calendarView.__daySlots), __days(calendarView.__days), onDisplay(calendarView.onDisplay)
{
}
CalendarView::CalendarView()
	: __daySlots(1), __days(new Date[1]) // For easy exception handling. This function won't be used anywhere by the user.
{
}
CalendarView::~CalendarView()
{
	delete onDisplay;
	for(unsigned short i(0); i < __daySlots; __days[i++]->~Day());
	::operator delete(__days);
}

void CalendarView::onShow()
{
	for(unsigned short i(0); i < __daySlots; onDisplay.execute(&(__days[i++])));
}
void CalendarView::onHide()
{
}
void CalendarView::display()
{
	if (__data != nullptr)
		((Calendar*)__data)->getView().onHide();
	onShow();
}

unsigned short CalendarView::daySlots()
{
	return __daySlots;
}
unsigned short CalendarView::dayCount()
{
	return GetMonthDayCount(__date);
}
void CalendarView::createFromDate(Date const &date)
{
	unsigned short
		index(GetDateDayIndex(&date)),
		startIndex(index - (date.day() - 1));

	for(unsigned short i(0); i < __dayCount; ++i)
		new (__days + i) Date(max(GetMonthDayCount(&date), min(0, i - startIndex + 1)));
}