// nativecalendar.cpp
#include "nativecalendarapp.hpp"

using namespace NativeCalendarApp;

#define __ NativeCalendar


void __::InitData(__ *calendar)
{
	((NativeCalendarView*)(calendar->__weekView))->__data = calendar;
	((NativeCalendarView*)(calendar->__monthView))->__data = calendar;
}

__::__(NativeCalendarViewType viewType)
	: __viewType(viewType), __weekView(new NativeWeekView), __monthView(new NativeMonthView)
{
	InitData(this);
}
__::__(__ const &calendar)
	: __viewType(calendar.__viewType), __weekView(new NativeWeekView), __monthView(new NativeMonthView)
{
	*__weekView = NativeWeekView(*calendar.__weekView);
	*__monthView = NativeMonthView(*calendar.__monthView);
	InitData(this);
}
__::__()
	: __viewType(NativeCalendarViewType::MONTH_VIEW), __weekView(new NativeWeekView), __monthView(new NativeMonthView)
{
	InitData(this);
}
__::~__()
{
	delete __weekView;
	delete __monthView;
}

void __::goToDate(NativeDate const &date)
{
	if (*__date != date)
	{
		unsigned short
			dayIndex(const_cast<NativeDate&>(date).getDayIndex()),
			index;
		for (short i(0); i < getView().__daySlots; ++i)
		{
			index = i - dayIndex + 1;
			if (index > 0 && index <= const_cast<NativeDate&>(date).getMonthDayCount())
				getView().__days[index].__day = index;
		}
	}
}
NativeCalendarView &__::getView()
{
	switch (__viewType)
	{
		case NativeCalendarViewType::WEEK_VIEW:
			return *((NativeCalendarView*)__weekView);

		case NativeCalendarViewType::MONTH_VIEW:
			return *((NativeCalendarView*)__monthView);
	}
}

NativeCalendarViewType __::getViewType() const
{
	return __viewType;
}
void __::setViewType(NativeCalendarViewType viewType)
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

#undef __