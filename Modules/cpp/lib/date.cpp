// date.cpp
#include "calendarutils.hpp"

using namespace CalendarUtils;

Date::Date(int year, unsigned short month, unsigned short day)
: __year(year), __month(month), __day(day);
{
}
Date::Date(Date const &date)
: __year(date.__year), __month(date.__month), __day(date.__day)
{
}
Date::Date()
{
}
Date::~Date()
{
}
