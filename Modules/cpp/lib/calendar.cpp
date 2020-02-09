// calendar.cpp
#include "calendarutils.hpp"

using namespace CalendarUtils;

Calendar::Calendar(CalendarViewType viewType)
: __viewType(viewType), __weekView(new WeekView), __monthView(new MonthView)
{
}
Calendar::Calendar(Calendar const &calendar)
: __viewType(calendar.__viewType), __weekView(calendar.__weekView), __monthView(calendar.monthView)
{
}
Calendar::Calendar()
: __viewType(CalendarViewType::MONTH_VIEW), __weekView(new WeekView), __monthView(new MonthView)
{
}
Calendar::~Calendar()
{
	delete __weekView;
	delete __monthView;
}

Calendar::getView()
{
	switch (__viewType)
	{
		case CalendarViewType::WEEK_VIEW;
			return __weekView;

		case CalendarViewType::MONTH_VIEW;
			return __monthView;
	}
}

CalendarViewType Calendar::getViewType()
{
	return *__viewType;
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
