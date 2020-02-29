// nativecalendar.cpp
#include "nativecalendarapp.hpp"
#include "nativecalendarutils.hpp"

using namespace NativeCalendarApp;

void NativeCalendar::InitData(NativeCalendar *calendar)
{
	((NativeCalendarView*)(calendar->__weekView))->__data = calendar;
	((NativeCalendarView*)(calendar->__monthView))->__data = calendar;
}

NativeCalendar::NativeCalendar(NativeCalendarViewType viewType)
	: __viewType(viewType), __weekView(new NativeWeekView), __monthView(new NativeMonthView)
{
	InitData(this);
}
NativeCalendar::NativeCalendar(NativeCalendar const &calendar)
	: __viewType(calendar.__viewType), __weekView(new NativeWeekView), __monthView(new NativeMonthView)
{
	*__weekView = NativeWeekView(*calendar.__weekView);
	*__monthView = NativeMonthView(*calendar.__monthView);
	InitData(this);
}
NativeCalendar::NativeCalendar()
	: __viewType(NativeCalendarViewType::MONTH_VIEW), __weekView(new NativeWeekView), __monthView(new NativeMonthView)
{
	InitData(this);
}
NativeCalendar::~NativeCalendar()
{
	delete __weekView;
	delete __monthView;
}

void NativeCalendar::goToDate(NativeDate const &date)
{
	if (*__date != date)
	{
		unsigned short
			dayIndex(GetDateDayIndex(date)),
			index;
		for (short i(0); i < getView().__daySlots; ++i)
		{
			index = i - dayIndex + 1;
			if (index > 0 && index <= GetMonthDayCount(date))
				getView().__days[index].__day = index;
		}
	}
}
NativeCalendarView &NativeCalendar::getView()
{
	switch (__viewType)
	{
		case NativeCalendarViewType::WEEK_VIEW:
			return *((NativeCalendarView*)__weekView);

		case NativeCalendarViewType::MONTH_VIEW:
			return *((NativeCalendarView*)__monthView);
	}
}

NativeCalendarViewType NativeCalendar::getViewType() const
{
	return __viewType;
}
void NativeCalendar::setViewType(NativeCalendarViewType viewType)
{
	__viewType = viewType;
	switch (viewType)
	{
		case NativeCalendarViewType::WEEK_VIEW:
			break;

		case NativeCalendarViewType::MONTH_VIEW:
			break;
	}
}
