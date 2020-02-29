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