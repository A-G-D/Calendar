#pragma once

#ifndef __CALENDAR_UTILS_HPP__
#define __CALENDAR_UTILS_HPP__

#include <vector>

namespace CalendarUtils
{

	class Calendar;
	class WeekView;
	class MonthView;
	class Date;
	class Day;
	class Reminder;

	enum CalendarViewType
	{
		WEEK_VIEW,
		MONTH_VIEW
	};

	namespace
	{
		class Event;

		class CalendarView
		{
		private:

			CalendarView();

		protected:

			unsigned short __dayCount;
			Day *__days;

		public:

			Event *onClick;

			virtual void display();
			virtual void createFromDate(Date const &date);

			CalendarView(unsigned short dayCount);
			CalendarView(CalendarView const &calendarView);
			virtual ~CalendarView();
		};
	}

	class Calendar
	{
	private:

		CalendarViewType __viewType;
		WeekView *__weekView;
		MonthView *__monthView;

	public:

		CalendarView &getView() const;

		CalendarViewType getViewType() const;
		void setViewType(CalendarViewType view);

		Calendar();
		Calendar(Calendar const &calendar);
		~Calendar();
	};

	class WeekView : CalendarView
	{
	private:

		unsigned short __maxWeekCount;

	public:

		virtual void display() override;

		WeekView();
		WeekView(WeekView const &weekView);
		virtual ~WeekView();
	};

	class MonthView : CalendarView
	{
	private:

		

	public:

		virtual void display() override;

		MonthView();
		MonthView(MonthView const &monthView);
		virtual ~MonthView();
	};

	class Date
	{
	private:

		int __year;
		unsigned short
			__month,
			__day;

		Date();

	public:

		Date(int year, unsigned short month, unsigned short day);
		Date(Date const &date);
		~Date();
	};

	class Day
	{
	private:

		unsigned short __number;
		unsigned short __weekIndex;
		std::vector<Reminder> __reminders;

		Day();

	public:

		void addReminder(Reminder const &reminder);
		void clearReminders();

		Day(unsigned short dayNumber);
		Day(Day const &day);
		~Day();
	};

	class Reminder
	{
	private:

		unsigned short
			__hour,
			__minute,
			__second;

		Reminder();

	public:

		unsigned short hour() const;
		unsigned short minute() const;
		unsigned short second() const;

		std::string &toString() const;

		void update(unsigned short hour, unsigned short minute, unsigned short second);

		Reminder(unsigned short hour, unsigned short minute, unsigned short second);
		Reminder(Reminder const &reminder);
		~Reminder();
	};
}
#endif

#pragma endregion
