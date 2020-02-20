// calendar.cpp
#include "calendarutils.hpp"
#include "utils.hpp"

using namespace CalendarUtils;

void Calendar::InitData(Calendar *calendar)
{
	calendar->__weekView->__data = calendar;
	calendar->__monthView->__data = calendar;
}

Calendar::Calendar(CalendarViewType viewType)
	: __viewType(viewType), __weekView(new WeekView), __monthView(new MonthView)
{
	InitData(this);
}
Calendar::Calendar(Calendar const &calendar)
	: __viewType(calendar.__viewType), __weekView(new WeekView), __monthView(new MonthView)
{
	*__weekView = WeekView(*calendar.__weekView);
	*__monthView = MonthView(*calendar.__monthView);
	InitData(this);
}
Calendar::Calendar()
	: __viewType(CalendarViewType::MONTH_VIEW), __weekView(new WeekView), __monthView(new MonthView)
{
	InitData(this);
}
Calendar::~Calendar()
{
	delete __weekView;
	delete __monthView;
}

void Calendar::goToDate(Date const &date)
{
	if (*__date != date)
	{
		unsigned short
			dayIndex(GetDateDayIndex(&date)),
			index;
		for (short i(0); i < getView().__daySlots; ++i)
		{
			index = i - dayIndex + 1;
			if (index > 0 && index <= GetMonthDayCount(&date))
				getView().__days[index].__day = index;
		}
	}
}
CalendarView &Calendar::getView()
{
	switch (__viewType)
	{
		case CalendarViewType::WEEK_VIEW:
			return *__weekView;

		case CalendarViewType::MONTH_VIEW:
			return *__monthView;
	}
}

CalendarViewType Calendar::getViewType() const
{
	return __viewType;
}
void Calendar::setViewType(CalendarViewType viewType)
{
	__viewType = viewType;
	switch (viewType)
	{
		case CalendarViewType::WEEK_VIEW:
			break;

		case CalendarViewType::MONTH_VIEW:
			break;
	}
}