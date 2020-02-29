// nativecalendarview.cpp
#include "nativecalendarapp.hpp"
#include "nativecalendarutils.hpp"
#include "nativeevent.hpp"
#include <algorithm>

using namespace NativeCalendarApp;
using namespace std;

NativeCalendarView::NativeCalendarView(unsigned short daySlots)
	: __daySlots(daySlots), __days(static_cast<NativeDate*>(::operator new(sizeof(NativeDate)*daySlots))), onDisplay(new NativeEvent)
{
}
NativeCalendarView::NativeCalendarView(NativeCalendarView const &calendarView)
	: __daySlots(calendarView.__daySlots), __days(calendarView.__days), onDisplay(calendarView.onDisplay)
{
}
NativeCalendarView::NativeCalendarView()
	: __daySlots(1), __days(new NativeDate(1, 1, 1)) // For easy exception handling. This function won't be used anywhere by the user.
{
}
NativeCalendarView::~NativeCalendarView()
{
	delete onDisplay;
	for(unsigned short i(0); i < __daySlots; __days[i++].~NativeDate());
	::operator delete(__days);
}

void NativeCalendarView::onShow()
{
	for(unsigned short i(0); i < __daySlots; onDisplay->execute(&(__days[i++])));
}
void NativeCalendarView::onHide()
{
}
void NativeCalendarView::display()
{
	if (__data != nullptr)
		((NativeCalendar*)__data)->getView().onHide();
	onShow();
}

unsigned short NativeCalendarView::daySlots() const
{
	return __daySlots;
}
unsigned short NativeCalendarView::dayCount() const
{
	return GetMonthDayCount(__days[0]);
}
void NativeCalendarView::createFromDate(NativeDate const &date)
{
	unsigned short
		index(GetDateDayIndex(date)),
		startIndex(index - (date.day() - 1));

	for(unsigned short i(0); i < dayCount(); ++i)
		new (__days + i) NativeDate(date.year(), date.month(), max((int)GetMonthDayCount(date), min(0, i - startIndex + 1)));
}