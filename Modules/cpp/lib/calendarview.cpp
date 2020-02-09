// calendarview.cpp
#include "calendarutils.hpp"
#include "utils.hpp"
#include "event.hpp"
#include <algorithm>

using namespace CalendarUtils;
using namespace std;

CalendarView::CalendarView(unsigned short dayCount)
: __dayCount(dayCount), __days(static_cast<Day*>(::operator new(sizeof(Day)*dayCount))), onClick(new Event)
{
}
CalendarView::CalendarView(CalendarView const &calendarView)
: __dayCount(calendarView.__dayCount), __days(calendarView.__days)
{
}
CalendarView::CalendarView()
: __dayCount(1), __days(new Day[1]) // For easy exception handling. This function won't be used anywhere by the user.
{
}
CalendarView::~CalendarView()
{
	delete onClick;
	for(unsigned short i(0); i < __dayCount; __days[i++]->~Day());
	::operator delete(__days);
}

void CalendarView::display()
{
	for(unsigned short i(0); i < __dayCount; onClick.execute(&(__days[i++])));
}
void CalendarView::createFromDate(Date const &date)
{
	unsigned short
		weekPosition(GetDateWeekPosition(&date)),
		modulu(date.day()%7);
	if (!modulu)
		modulu = 7;
	unsigned short
		index(GetDateDayIndex(&date)),
		startIndex(index - (date.day() - 1));

	for(unsigned short i(0); i < __dayCount; ++i)
		new (__days + i) Day(max(GetMonthDayCount(&date), min(0, i - startIndex + 1)));
}
