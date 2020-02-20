#pragma once

#ifndef __CALENDAR_UTILS_HPP__
#define __CALENDAR_UTILS_HPP__
/******************************************************************************
*
*	API
*
*	namespace CalendarUtils
*
*		enum CalendarViewType
*
*			WEEK_VIEW
*			MONTH_VIEW
*
*
*		class Calendar
*
*		(Constructors)
*
*			Calendar()
*			Calendar(Calendar const &calendar)
*
*		(Methods)
*			CalendarView &getView()
*			CalendarViewType getViewType()
*			void setViewType(CalendarViewType view)
*
*
*		class WeekView
*
*		(Constructors)
*
*			WeekView()
*			WeekView(WeekView const &weekView)
*
*		(Fields)
*
*			Event *onClick
*
*		(Methods)
*
*			unsigned short getMaxWeekCount()
*			void setMaxWeekCount(unsigned short count)
*
*			virtual void onShow()
*			virtual void onHide()
*			virtual void display()
*
*
*		class MonthView
*
*		(Constructors)
*
*			MonthView()
*			MonthView(MonthView const &monthView)
*
*		(Fields)
*
*			Event *onClick
*
*		(Methods)
*
*			virtual void onShow()
*			virtual void onHide()
*			virtual void display()
*
*
*		class Date
*
*
*		class Day
*
*
*		class Reminder
*
*******************************************************************************/

#include <vector>
#include <string>

namespace CalendarUtils
{

	class Calendar;
	class WeekView;
	class MonthView;
	class Date;
	class Reminder;

	enum CalendarViewType
	{
		WEEK_VIEW,
		MONTH_VIEW
	};

	class Event;

	class CalendarView
	{
	private:

		friend class Calendar;

		Calendar *__calendar;

		CalendarView();

	protected:

		unsigned short __daySlots;
		Date *__days;

		virtual void onShow();
		virtual void onHide();

	public:

		void *__data;
		Event *onDisplay;

		unsigned short daySlots() const;

		virtual unsigned short dayCount();

		virtual void display();
		virtual void createFromDate(Date const &date);

		CalendarView(unsigned short dayCount);
		CalendarView(CalendarView const &calendarView);
		virtual ~CalendarView();
	};

	class Calendar
	{
	private:

		CalendarViewType __viewType;
		WeekView *__weekView;
		MonthView *__monthView;
		Date *__date;

		void InitData(Calendar *calendar);

	public:

		void goToDate(Date const &date);

		CalendarView &getView();
		CalendarViewType getViewType() const;
		void setViewType(CalendarViewType view);

		Calendar(CalendarViewType viewType);
		Calendar(Calendar const &calendar);
		Calendar();
		~Calendar();
	};

	class WeekView : CalendarView
	{
	private:

		unsigned short __maxWeekCount;

	protected:

		virtual void onShow() override;
		virtual void onHide() override;

	public:

		unsigned short getMaxWeekCount() const;
		void setMaxWeekCount(unsigned short count);

		virtual unsigned short dayCount() override;

		virtual void display() override;

		WeekView(unsigned short maxWeekCount);
		WeekView(WeekView const &weekView);
		WeekView();
		virtual ~WeekView();
	};

	class MonthView : CalendarView
	{
	private:

		

	protected:

		virtual void onShow() override;
		virtual void onHide() override;

	public:

		virtual void display() override;

		MonthView(MonthView const &monthView);
		MonthView();
		virtual ~MonthView();
	};

	class Date
	{
	private:

		friend class Calendar;

		unsigned short
			__day,
			__month;
		int __year;
		std::vector<Reminder> *__reminders;

		Date();

	public:

		static Date const &today();

		bool operator==(Date const &date);
		bool operator!=(Date const &date);
		bool operator<(Date const &date);
		bool operator>(Date const &date);
		bool operator<=(Date const &date);
		bool operator>=(Date const &date);

		unsigned short day() const;
		unsigned short month() const;
		int year() const;

		std::vector<Reminder> getReminders();
		void addReminder(Reminder const &reminder);
		void clearReminders();

		Date(int year, unsigned short month, unsigned short day);
		Date(Date const &date);
		~Date();
	};

	class Reminder
	{
	private:

		unsigned short
			__hour,
			__minute,
			__second;

		std::string __note;

		Reminder();

	public:

		unsigned short hour() const;
		unsigned short minute() const;
		unsigned short second() const;
		std::string &note() const;

		std::string toString();

		void update(unsigned short hour, unsigned short minute, unsigned short second);

		Reminder(unsigned short hour, unsigned short minute, unsigned short second);
		Reminder(Reminder const &reminder);
		~Reminder();
	};
}
#endif

#pragma endregion