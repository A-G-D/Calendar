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
#pragma once

#ifndef __NATIVECALENDARAPP_HPP__
#define __NATIVECALENDARAPP_HPP__

#include <vector>
#include <string>

class NativeEvent;

namespace NativeCalendarApp
{

	class NativeCalendar;
	class NativeWeekView;
	class NativeMonthView;
	class NativeDate;
	class NativeReminder;

	enum NativeCalendarViewType
	{
		WEEK_VIEW,
		MONTH_VIEW
	};


	class NativeCalendarView
	{
	private:

		friend class NativeCalendar;

		NativeCalendar *__calendar;

		NativeCalendarView();

	protected:

		unsigned short __daySlots;
		NativeDate *__days;

		virtual void onShow();
		virtual void onHide();

	public:

		void *__data;
		NativeEvent *onDisplay;

		virtual unsigned short daySlots() const;
		virtual unsigned short dayCount() const;

		virtual void display();
		virtual void createFromDate(NativeDate const &date);

		NativeCalendarView(unsigned short dayCount);
		NativeCalendarView(NativeCalendarView const &calendarView);
		virtual ~NativeCalendarView();
	};

	class NativeCalendar
	{
	private:

		NativeCalendarViewType __viewType;
		NativeWeekView *__weekView;
		NativeMonthView *__monthView;
		NativeDate *__date;

		void InitData(NativeCalendar *calendar);

	public:

		void goToDate(NativeDate const &date);

		NativeCalendarView &getView();
		NativeCalendarViewType getViewType() const;
		void setViewType(NativeCalendarViewType view);

		NativeCalendar(NativeCalendarViewType viewType);
		NativeCalendar(NativeCalendar const &calendar);
		NativeCalendar();
		~NativeCalendar();
	};

	class NativeWeekView : NativeCalendarView
	{
	private:

		unsigned short __maxWeekCount;

	protected:

		virtual void onShow() override;
		virtual void onHide() override;

	public:

		unsigned short getMaxWeekCount();
		void setMaxWeekCount(unsigned short count);

		virtual unsigned short daySlots() const override;
		virtual unsigned short dayCount() const override;

		virtual void display() override;

		NativeWeekView(unsigned short maxWeekCount);
		NativeWeekView(NativeWeekView const &weekView);
		NativeWeekView();
		virtual ~NativeWeekView();
	};

	class NativeMonthView : NativeCalendarView
	{
	private:

		

	protected:

		virtual void onShow() override;
		virtual void onHide() override;

	public:

		virtual void display() override;

		NativeMonthView(NativeMonthView const &monthView);
		NativeMonthView();
		virtual ~NativeMonthView();
	};

	class NativeDate
	{
	private:

		friend class NativeCalendar;

		unsigned short
			__day,
			__month;
		int __year;
		std::vector<NativeReminder> *__reminders;

		NativeDate();

	public:

		static NativeDate const &today();

		bool operator==(NativeDate const &date);
		bool operator!=(NativeDate const &date);
		bool operator<(NativeDate const &date);
		bool operator>(NativeDate const &date);
		bool operator<=(NativeDate const &date);
		bool operator>=(NativeDate const &date);

		unsigned short day() const;
		unsigned short month() const;
		int year() const;

		bool isLeapYear() const;

		int getDistance(NativeDate const &date);
		unsigned short getWeekPosition();
		unsigned short getDayIndex();
		unsigned short getMonthDayCount();

		std::vector<NativeReminder> getReminders();
		void addReminder(NativeReminder const &reminder);
		void clearReminders();

		NativeDate(int year, unsigned short month, unsigned short day);
		NativeDate(NativeDate const &date);
		~NativeDate();
	};

	class NativeReminder
	{
	private:

		unsigned short
			__hour,
			__minute,
			__second;

		std::string __note;

		NativeReminder();

	public:

		unsigned short hour() const;
		unsigned short minute() const;
		unsigned short second() const;
		std::string &note();

		std::string toString() const;

		void update(unsigned short hour, unsigned short minute, unsigned short second);

		NativeReminder(unsigned short hour, unsigned short minute, unsigned short second);
		NativeReminder(NativeReminder const &reminder);
		~NativeReminder();
	};
}
#endif

#pragma endregion