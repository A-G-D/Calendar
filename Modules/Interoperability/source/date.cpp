#include "calendarapp.hpp"

using namespace CalendarApp;

Date ^Date::today()
{
	return gcnew Date(NativeDate::today().year(), NativeDate::today().month(), NativeDate::today().day());
}

bool Date::operator==(Date const ^date)
{
	return *__ptr == *date->__ptr;
}
bool Date::operator!=(Date const ^date)
{
	return *__ptr != *date->__ptr;
}
bool Date::operator<(Date const ^date)
{
	return *__ptr < *date->__ptr;
}
bool Date::operator>(Date const ^date)
{
	return *__ptr > *date->__ptr;
}
bool Date::operator<=(Date const ^date)
{
	return *__ptr <= *date->__ptr;
}
bool Date::operator>=(Date const ^date)
{
	return *__ptr >= *date->__ptr;
}

unsigned short Date::day()
{
	return __ptr->day();
}
unsigned short Date::month()
{
	return __ptr->month();
}
int Date::year()
{
	return __ptr->year();
}

bool Date::isLeapYear()
{
	return __ptr->isLeapYear();
}

int Date::getDistance(Date ^date)
{
	return __ptr->getDistance(*(date->__ptr));
}
unsigned short Date::getWeekPosition()
{
	return __ptr->getWeekPosition();
}
unsigned short Date::getDayIndex()
{
	return __ptr->getDayIndex();
}
unsigned short Date::getMonthDayCount()
{
	return __ptr->getMonthDayCount();
}

List<Reminder^> ^Date::getReminders()
{
	std::vector<NativeReminder> const &vec(__ptr->getReminders());
	List<Reminder^> ^list;
	for (unsigned short i(0); i < vec.size(); ++i)
		list->Add(gcnew Reminder(vec[i].hour(), vec[i].minute(), vec[i].second()));
	return list;
}
void Date::addReminder(Reminder ^reminder)
{
	__ptr->addReminder(*(reminder->__ptr));
}
void Date::clearReminders()
{
	__ptr->clearReminders();
}

Date::Date(int year, unsigned short month, unsigned short day)
	: __ptr(new NativeDate(year, month, day))
{
}
Date::Date(Date const ^date)
	: __ptr(new NativeDate(*(date->__ptr)))
{
}
Date::~Date()
{
	this->!Date();
}
Date::!Date()
{
	delete __ptr;
}