// day.cpp
#include "calendarutils.hpp"

using namespace CalendarUtils;

Day::Day(unsigned short dayNumber)
: __number(dayNumber)
{
}
Day::Day(Day const &day)
: __number(day.__number), __weekIndex(day.__weekIndex), __reminders(day.__reminders)
{
}
Day::Day()
{
}
Day::~Day()
{
	clearReminders();
}

void Day::addReminder(Reminder const &reminder)
{
	reminders.push_back(reminder);
}
void Day::clearReminders()
{
	reminders.clear();
}
