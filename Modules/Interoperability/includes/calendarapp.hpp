/*
*	<calendarapp.hpp>
*
*
*	|-----|
*	| API |
*	|-----|
*
*	namespace CalendarApp
*
*
*		enum CalendarViewType
*			WEEK_VIEW
*			MONTH_VIEW
*
*
*		class Calendar
*
*			Calendar(CalendarViewType viewType)
*			Calendar(Calendar const calendar)
*			Calendar()
*				- Constructors
*				- Ex: "Calendar c = new Calendar(CalendarViewType.MONTH_VIEW);" or "Calendar c = new Calendar;"
*
*			void goToDate(Date date)
*				- Goes to a certain date
*
*			CalendarView getView()
*				- Returns the CalendarView instance
*			CalendarViewType getViewType()
*				- Returns the CalendarViewType
*			void setViewType(CalendarViewType view)
*				- Sets the view type of the calendar to a new value
*
*
*		class CalendarView
*
*			CalendarView(unsigned short dayCount)
*			CalendarView(CalendarView const calendarView)
*				- Constructors
*
*			unsigned short daySlots()
*				- Returns the number of day slots in the current displayed instance
*			unsigned short dayCount()
*				- Returns the number of days in the current displayed instance
*
*			virtual void display()
*				- Displays this instance and hides the previous view
*			void createFromDate(Date ^date)
*				- Initializes the control components attached to this view
*
*
*		class WeekView
*
*			WeekView(unsigned short maxWeekCount)
*			WeekView(WeekView const weekView)
*			WeekView()
*				- Constructors
*
*			unsigned short getMaxWeekCount()
*				- Returns the number of weeks displayed in one view
*			void setMaxWeekCount(unsigned short count)
*				- Updates the number of weeks displayed in one view
*
*			unsigned short daySlots()
*				- Returns the number of day slots in the current displayed instance
*			unsigned short dayCount()
*				- Returns the number of days in the current displayed instance
*
*			virtual void display()
*				- Displays this instance and hides the previous view
*
*
*		class MonthView
*
*			MonthView(MonthView const monthView)
*			MonthView()
*
*			virtual void display()
*
*
*		class Date
*
*			Date(int year, unsigned short month, unsigned short day)
*			Date(Date const date)
*				- Constructors
*
*			static Date today()
*				- Returns the Date object with attributes set for today
*
*			bool operator==(Date const date)
*			bool operator!=(Date const date)
*			bool operator<(Date const date)
*			bool operator>(Date const date)
*			bool operator<=(Date const date)
*			bool operator>=(Date const date)
*				- Relational Operators: Date 'a' is less than Date 'b' if 'a' is earlier than 'b' in the timeline
*
*			unsigned short day()
*			unsigned short month()
*			int year()
*				- Date attributes: day, month, and year
*				- Years B.C.E. are negative
*
*			bool isLeapYear()
*
*			int getDistance(Date date)
*				- Gets the number of days between 'this' and 'date'
*				- Returns negative if 'this' > 'date'
*			unsigned short getWeekPosition()
*				- Returns a value (0 - 6) corresponding to the position of the specific Date in the week
*				- 0 = Sunday; 6 = Saturday
*			unsigned short getDayIndex()
*				- Index counts from 0 to 34 since the array size of the Dates of a month is 7*5 = 35
*			unsigned short getMonthDayCount()
*
*			List<Reminder> getReminders()
*				- Returns the list of Reminders for this Date
*			void addReminder(Reminder reminder)
*				- Appends a new Reminder to this Date
*			void clearReminders()
*				- Removes all Reminders for this Date
*
*
*		class Reminder
*
*			Reminder(unsigned short hour, unsigned short minute, unsigned short second)
*			Reminder(Reminder const reminder)
*				- Constructors
*
*			unsigned short hour()
*			unsigned short minute()
*			unsigned short second()
*				- Returns the time attributes of this Reminder
*			String note()
*				- Returns the note attached to this Reminder
*
*			String toString()
*				- Returns "HH : MM : SS"
*
*			void update(unsigned short hour, unsigned short minute, unsigned short second)
*				- Updates the time for this Reminder
*
*/
#pragma once

#ifndef __CALENDARAPP_HPP__
#define __CALENDARAPP_HPP__

#include "namespaces.hpp"
#include <nativecalendarapp.hpp>

namespace CalendarApp
{
	using namespace NativeCalendarApp;

	ref class Calendar;
	ref class CalendarView;
	ref class WeekView;
	ref class MonthView;
	ref class Date;
	ref class Reminder;

	enum CalendarViewType
	{
		WEEK_VIEW = NativeCalendarViewType::WEEK_VIEW,
		MONTH_VIEW = NativeCalendarViewType::MONTH_VIEW
	};

	ref class CalendarView
	{
	private:


	protected:

		!CalendarView();

	public:

		NativeCalendarView *__ptr;

		unsigned short daySlots();
		unsigned short dayCount();

		virtual void display();
		void createFromDate(Date ^date);

		CalendarView(unsigned short dayCount);
		CalendarView(NativeCalendarView const &nativeCalendarView);
		CalendarView(CalendarView const ^calendarView);
		virtual ~CalendarView();

	};

	ref class Calendar
	{
	private:


	protected:

		!Calendar();

	public:

		NativeCalendar *__ptr;

		void goToDate(Date ^date);

		CalendarView ^getView();
		CalendarViewType getViewType();
		void setViewType(CalendarViewType view);

		Calendar(CalendarViewType viewType);
		Calendar(Calendar const ^calendar);
		Calendar();
		virtual ~Calendar();
	};

	ref class WeekView
	{
	private:


	protected:

		!WeekView();

	public:

		NativeWeekView *__ptr;

		unsigned short getMaxWeekCount();
		void setMaxWeekCount(unsigned short count);

		unsigned short daySlots();
		unsigned short dayCount();

		virtual void display();

		WeekView(unsigned short maxWeekCount);
		WeekView(WeekView const ^weekView);
		WeekView();
		virtual ~WeekView();
	};

	ref class MonthView
	{
	private:


	protected:

		!MonthView();

	public:

		NativeMonthView *__ptr;

		virtual void display();

		MonthView(MonthView const ^monthView);
		MonthView();
		virtual ~MonthView();
	};

	ref class Date
	{
	private:


	protected:

		!Date();

	public:

		NativeDate *__ptr;

		static Date ^today();

		bool operator==(Date const ^date);
		bool operator!=(Date const ^date);
		bool operator<(Date const ^date);
		bool operator>(Date const ^date);
		bool operator<=(Date const ^date);
		bool operator>=(Date const ^date);

		unsigned short day();
		unsigned short month();
		int year();

		bool isLeapYear();

		int getDistance(Date ^date);
		unsigned short getWeekPosition();
		unsigned short getDayIndex();
		unsigned short getMonthDayCount();

		List<Reminder^> ^getReminders();
		void addReminder(Reminder ^reminder);
		void clearReminders();

		Date(int year, unsigned short month, unsigned short day);
		Date(Date const ^date);
		virtual ~Date();
	};

	ref class Reminder
	{
	private:


	protected:

		!Reminder();

	public:

		NativeReminder *__ptr;

		unsigned short hour();
		unsigned short minute();
		unsigned short second();
		String ^note();

		String ^toString();

		void update(unsigned short hour, unsigned short minute, unsigned short second);

		Reminder(unsigned short hour, unsigned short minute, unsigned short second);
		Reminder(Reminder const ^reminder);
		virtual ~Reminder();
	};
}

#endif

#pragma endregion