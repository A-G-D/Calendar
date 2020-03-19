// nativecalendarview.cpp
#include "nativecalendarapp.hpp"
#include "nativeevent.hpp"
#include <algorithm>

using namespace NativeCalendarApp;
using namespace std;

#define __ NativeCalendarView


__::__(unsigned short daySlots)
	: __daySlots(daySlots), __days(static_cast<NativeDate*>(::operator new(sizeof(NativeDate)*daySlots))), onDisplay(new NativeEvent)
{
}
__::__(__ const &calendarView)
	: __daySlots(calendarView.__daySlots), __days(calendarView.__days), onDisplay(calendarView.onDisplay)
{
}
__::__()
	: __daySlots(1), __days(new NativeDate(1, 1, 1)) // For easy exception handling. This function won't be used anywhere by the user.
{
}
__::~__()
{
	delete onDisplay;
	for(unsigned short i(0); i < __daySlots; __days[i++].~NativeDate());
	::operator delete(__days);
}

void __::onShow()
{
	for(unsigned short i(0); i < __daySlots; onDisplay->execute(&(__days[i++])));
}
void __::onHide()
{
}
void __::display()
{
	if (__data != nullptr)
		((NativeCalendar*)__data)->getView().onHide();
	onShow();
}

unsigned short __::daySlots() const
{
	return __daySlots;
}
unsigned short __::dayCount() const
{
	return __days[0].getMonthDayCount();
}
void __::createFromDate(NativeDate const &date)
{
	unsigned short
		index(const_cast<NativeDate&>(date).getDayIndex()),
		startIndex(index - (date.day() - 1));

	for(unsigned short i(0); i < dayCount(); ++i)
		new (__days + i) NativeDate(date.year(), date.month(), max((int)(const_cast<NativeDate&>(date).getMonthDayCount()), min(0, i - startIndex + 1)));
}