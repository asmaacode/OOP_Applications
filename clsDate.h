#pragma once
#pragma warning(disable : 4996) 
#include<ctime> 
#include<iomanip>
#include "clsString.h"
#include "clsInputValidate.h"
#include "clsUtils.h"

class clsDate
{
private:
	short _day = 0, _month = 0, _year = 0;
public:
	clsDate() {
		_day = getThisDay();
		_month = getThisMonth();
		_year = getThisYear();
	};
	clsDate(short day, short month, short year) {
		_day = day;
		_month = month;
		_year = year;
	};
	clsDate(string stringDate) {
		*this = stringToDate(stringDate);
	};
	clsDate(short days, short year) {
		_day = 1, _month = 1, _year = year;
		*this = addXDay(*this, days);
	};

	void setDay(short day) {
		_day = day;
	};
	short getDay() {
		return _day;
	};
	__declspec(property(get = getDay, put = setDay)) short _day;
	void setMonth(short month) {
		_month = month;
	};
	short getMonth() {
		return _month;
	};
	__declspec(property(get = getMonth, put = setMonth)) short _month;

	void setYear(short year) {
		_year = year;
	};
	short getYear() {
		return _year;
	};
	__declspec(property(get = getYear, put = setYear)) short _year;

	static short getThisYear() {
		time_t t = time(0);
		tm* now = localtime(&t);
		return now->tm_year + 1900;
	}
	static short getThisMonth() {
		time_t t = time(0);
		tm* now = localtime(&t);
		return now->tm_mon + 1;
	};
	static short getThisDay() {
		time_t t = time(0);   //
		tm* now = localtime(&t);
		return  now->tm_mday;
	};
	static short getThisHour() {
		time_t t = time(0);   //
		tm* now = localtime(&t);
		return now->tm_hour;
	};

	void print() {
		cout << _day << "/" << _month << "/" << _year;
	};
	static clsDate getSystemDate() {
		clsDate today;
		today._day = getThisDay();
		today._month = getThisMonth();
		today._year = getThisYear();
		return today;
	};
	static bool isLeapYear(short year) {
		return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
	};
	bool isLeapYear() {
		return isLeapYear(_year);
	};
	static bool isValidDate(clsDate date) {
		return(date._month >= 1 && date._month <= 12 &&
			date._day >= 1 && date._day <= countDaysInMonth(date._year, date._month));
	};
	bool isValid() {
		return isValidDate(*this);
	};
	static bool isDate1BeforeDate2(clsDate date1, clsDate date2) {
		return (date1._year < date2._year) ? true :
			(date1._year == date2._year) ? (date1._month < date2._month) ? true :
			(date1._month == date2._month) ? (date1._day < date2._day) : false : false;
	};
	bool isDate1BeforeDate2(clsDate date2) {
		return isDate1BeforeDate2(*this, date2);
	};
	static bool isDate1EqualDate2(clsDate date1, clsDate date2) {
		return date1._year == date2._year && date1._month == date2._month && date1._day == date2._day;
	};
	bool isDate1EqualDate2(clsDate date2) {
		return isDate1EqualDate2(*this, date2);
	};
	static bool isDate1AfterDate2(clsDate date1, clsDate date2) {
		return (!isDate1BeforeDate2(date1, date2));
	};
	bool isDate1AfterDate2(clsDate date2) {
		return isDate1AfterDate2(*this, date2);
	};
	static bool isLastDayInMonth(clsDate date) {
		return date._day == countDaysInMonth(date._year, date._month);
	};
	bool isLastDayInMonth() {
		return isLastDayInMonth(*this);
	};
	static bool isLastMonthInYear(short month) {
		return month == 12;
	};
	bool isLastMonthInYear() {
		return isLastMonthInYear(_month);
	};
	static bool isEndOfWeek(clsDate date) {
		return getOrderWeekDayOfDate(date) == 6;
	};
	bool isEndOfWeek() {
		return isEndOfWeek(*this);
	};
	static bool isWeekend(clsDate date) {
		short dateOrder = getOrderWeekDayOfDate(date);
		return dateOrder == 5 || dateOrder == 6;
	};
	bool isWeekend() {
		return isWeekend(*this);
	};
	static bool isBusinessDay(clsDate date) {
		return !isWeekend(date);
	}
	bool isBusinessDay() {
		return isBusinessDay(*this);
	};

	enum enCompareDate { Before = -1, Equal = 0, After = 1 };
	static enCompareDate compareDates(clsDate date1, clsDate date2) {
		return
			isDate1BeforeDate2(date1, date2) ? enCompareDate::Before :
			isDate1EqualDate2(date1, date2) ? enCompareDate::Equal :
			enCompareDate::After;
	};

	static short countDaysInYear(short year) {
		return (isLeapYear(year)) ? 366 : 365;
	}
	short countDaysInYear() {
		return countDaysInYear(_year);
	};
	static short countHoursInYear(short year) {
		return countDaysInYear(year) * 24;
	}
	short countHoursInYear() {
		return countHoursInYear(_year);
	};
	static int countMinutesInYear(short year) {
		return countDaysInYear(year) * 60;
	}
	int countMinutesInYear() {
		return countMinutesInYear(_year);
	};
	static int countSecondsInYear(short year) {
		return countDaysInYear(year) * 60;
	}
	int countSecondsInYear() {
		return countSecondsInYear(_year);
	};
	static  short countDaysInMonth(short year, short month) {
		if (month < 1 || month > 12) return 0;
		short days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		return (month == 2) ? (isLeapYear(year) ? 29 : 28) : days[month];
	};
	short countDaysInMonth() {
		return countDaysInMonth(_year, _month);
	};
	static short countHoursInMonth(short year, short month) {
		return countDaysInMonth(year, month) * 24;
	}
	short countHoursInMonth() {
		return countHoursInMonth(_year, _month);
	};
	static int countMinutesInMonth(short year, short month) {
		return countHoursInMonth(year, month) * 60;
	}
	int countMinutesInMonth() {
		return countMinutesInMonth(_year, _month);
	};
	static int countSecondsInMonth(short year, short month) {
		return countMinutesInMonth(year, month) * 60;
	}
	int countSecondsInMonth() {
		return countSecondsInMonth(_year, _month);
	};
	static short countDaysFromBeginingOfYear(short year, short month, short day) {
		for (short i = 1;i < month;i++) {
			day += countDaysInMonth(year, i);
		}
		return day;
	};
	static  short countDaysFromBeginingOfYear(clsDate date) {
		return countDaysFromBeginingOfYear(date._year, date._month, date._day);
	};
	short countDaysFromBeginingOfYear() {
		return countDaysFromBeginingOfYear(_year, _month, _day);
	};
	static short countDaysUntilEndOfWeek(clsDate date) {
		return 6 - getOrderWeekDayOfDate(date);
	};
	short countDaysUntilEndOfWeek() {
		return countDaysUntilEndOfWeek(*this);
	};
	static short countDaysUntilEndOfMonth(clsDate date) {
		return (countDaysInMonth(date._year, date._month) - date._day) + 1;
	};
	short countDaysUntilEndOfMonth() {
		return countDaysUntilEndOfMonth(*this);
	};
	static short countDaysUntilEndOfYear(clsDate date) {
		return (countDaysInYear(date._year) - countDaysFromBeginingOfYear(date)) + 1;
	};
	short countDaysUntilEndOfYear() {
		return countDaysUntilEndOfYear(*this);
	};

	static string getMonthName(short& month) {
		string monthsNames[] = { "","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
		return monthsNames[month];
	};
	static string getWeekDayName(short dayOrder) {
		string weekDays[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
		return weekDays[dayOrder];
	};

	static short getOrderWeekDayOfDate(short day, short month, short year) {
		short a = floor((14 - month) / 12);
		short y = year - a;
		short m = month + 12 * a - 2;
		short d = day + y + floor(y / 4) - floor(y / 100) + floor(y / 400) + floor(31 * m / 12);
		//short d = 5 + day + y + floor(y / 4) + floor(31 * m / 12);
		d = d % 7;
		return d;
	};
	static short getOrderWeekDayOfDate(clsDate date) {
		return getOrderWeekDayOfDate(date._day, date._month, date._year);
	};
	short getOrderWeekDayOfDate() {
		return getOrderWeekDayOfDate(_day, _month, _year);
	};

	static clsDate stringToDate(string stringDate) {
		clsDate date;
		try {
			vector<string>dateSliced = clsString::split(stringDate, "/");
			date._day = stoi(dateSliced.at(0));
			date._month = stoi(dateSliced.at(1));
			date._year = stoi(dateSliced.at(2));
		}
		catch (exception ex) {
			if (!isValidDate(date)) {
				cout << "Wrong input !!!\n";
				date._day = 1;
				date._month = 1;
				date._year = 1900;
			}
		}
		return date;
	};
	static void swapDates(clsDate& date1, clsDate& date2) {
		clsDate Temp = date1;
		date1 = date2;
		date2 = Temp;
	};
	static int getDifferenceDays(clsDate  date1, clsDate date2, bool includingEndDay = false) {
		int days = 0;
		while (isDate1BeforeDate2(date1, date2))
		{
			days++;
			date1 = addOneDay(date1);
		}
		return
			includingEndDay ? ++days : days;
	}
	int getDifferenceDays(clsDate date2, bool includingEndDay = false) {
		return getDifferenceDays(*this, date2, includingEndDay);
	};
	static string dateToString(clsDate date) {
		string stringDate;
		stringDate = to_string(date._day) + "/" + to_string(date._month) + "/" + to_string(date._year);
		return stringDate;
	}
	string dateToString() {
		return dateToString(*this);
	};
	static string dateFormat(clsDate date, string format = "dd/mm/yyyy") {
		string result = format;
		clsString::replace(result, "dd", to_string(date._day));
		clsString::replace(result, "mm", to_string(date._month));
		clsString::replace(result, "yyyy", to_string(date._year));
		return result;
	}

	static clsDate addDays(clsDate date, short days) {
		short remainingDays = days + countDaysFromBeginingOfYear(date._year, date._month, date._day);
		date._month = 1;
		short monthDays;
		while (true) {
			monthDays = countDaysInMonth(date._year, date._month);

			if (remainingDays > monthDays) {
				remainingDays = remainingDays - monthDays;
				date._month++;
				if (date._month > 12) {
					date._month = 1;
					date._year++;
				}
			}
			else {
				date._day = remainingDays;
				break;
			}

		}
		return date;
	}
	void addDays(short days) {
		*this = addDays(*this, days);
	};
	static clsDate addOneDay(clsDate date) {
		if (isLastDayInMonth(date)) {
			if (isLastMonthInYear(date._month)) {
				date._year++;
				date._month = 1;
			}
			else {
				date._month++;
			}
			date._day = 1;
		}
		else {
			date._day++;
		}
		return date;
	}
	void addOneDay() {
		*this = addOneDay(*this);
	};
	static clsDate addXDay(clsDate date, short days) {
		for (short i = 1;i <= days;i++) {
			date = addOneDay(date);
		}
		return date;
	};
	void addXDay(short days) {
		*this = addXDay(*this, days);
	};
	static clsDate addOneWeek(clsDate date)
	{
		for (short i = 1;i <= 7;i++) {
			date = addOneDay(date);
		}
		return date;
	}
	void addOneWeek()
	{
		*this = addOneWeek(*this);
	};
	static clsDate addXWeek(clsDate date, short weeks)
	{
		for (short i = 1;i <= weeks;i++) {
			date = addOneWeek(date);
		}
		return date;
	}
	void addXWeek(short weeks)
	{
		*this = addXWeek(*this, weeks);
	};
	static clsDate addOneMonth(clsDate date)
	{
		if (date._month >= 12)
		{
			date._month = 1;
			date._year++;
		}
		else {
			date._month++;
		}

		short days = countDaysInMonth(date._year, date._month);
		if (days < date._day) {
			date._day = days;
		}
		return date;
	}
	void addOneMonth()
	{
		*this = addOneMonth(*this);
	};
	static clsDate addXMonth(clsDate date, short months)
	{
		for (int i = 1; i <= months;i++) {
			date = addOneMonth(date);
		}
		return date;
	}
	void addXMonth(short months)
	{
		*this = addXMonth(*this, months);
	};
	static clsDate addOneYear(clsDate date)
	{
		date._year++;
		return date;
	}
	void addOneYear()
	{
		*this = addOneYear(*this);
	};
	static clsDate addXYear(clsDate date, short years)
	{
		date._year += years;
		return date;
	}
	void addXYear(short years)
	{
		*this = addXYear(*this, years);
	};
	static clsDate addOneDecade(clsDate date)
	{
		date._year += 10;
		return date;
	}
	void addOneDecade()
	{
		*this = addOneDecade(*this);
	};
	static clsDate addXDecade(clsDate date, short decades)
	{
		date._year += (10 * decades);
		return date;
	}
	void addXDecade(short decades)
	{
		*this = addXDecade(*this, decades);
	};
	static clsDate addOneCentury(clsDate date)
	{
		date._year += 100;
		return date;
	}
	void addOneCentury(short decades)
	{
		*this = addOneCentury(*this);
	};
	static clsDate addOneMillennium(clsDate date)
	{
		date._year += 1000;
		return date;
	}
	void addOneMillennium()
	{
		*this = addOneMillennium(*this);
	};

	static clsDate decreaseDateByOneDay(clsDate date) {
		if (date._day == 1) {
			if (date._month == 1) {
				date._year--;
				date._day = 31;
				date._month = 12;
			}
			else {
				date._month--;
				date._day = countDaysInMonth(date._year, date._month);
			}
		}
		else {
			date._day--;
		}
		return date;
	}
	void decreaseDateByOneDay() {
		*this = decreaseDateByOneDay(*this);
	};
	static clsDate decreaseDateByXDay(clsDate date, short days) {
		for (short i = 1;i <= days;i++) {
			date = decreaseDateByOneDay(date);
		}
		return date;
	}
	void decreaseDateByXDay(short days) {
		*this = decreaseDateByXDay(*this, days);
	};
	static clsDate decreaseDateByOneWeek(clsDate date)
	{
		for (short i = 1;i <= 7;i++) {
			date = decreaseDateByOneDay(date);
		}
		return date;
	}
	void decreaseDateByOneWeek() {
		*this = decreaseDateByOneWeek(*this);
	};
	static clsDate decreaseDateByXWeek(clsDate date, short weeks)
	{
		for (short i = 1;i <= weeks;i++) {
			date = decreaseDateByOneWeek(date);
		}
		return date;
	}
	void decreaseDateByXWeek(short weeks) {
		*this = decreaseDateByXWeek(*this, weeks);
	};
	static clsDate decreaseDateByOneMonth(clsDate date)
	{
		if (date._month == 1)
		{
			date._month = 12;
			date._year--;
		}
		else {
			date._month--;
		}

		short days = countDaysInMonth(date._year, date._month);
		if (days < date._day) {
			date._day = days;
		}
		return date;
	}
	void decreaseDateByOneMonth() {
		*this = decreaseDateByOneMonth(*this);
	};
	static clsDate decreaseDateByXMonth(clsDate date, short months)
	{
		for (int i = 1; i <= months;i++) {
			date = decreaseDateByOneMonth(date);
		}
		return date;
	}
	void decreaseDateByXMonth(short months) {
		*this = decreaseDateByXMonth(*this, months);
	};
	static clsDate decreaseDateByOneYear(clsDate date)
	{
		date._year--;
		return date;
	}
	void decreaseDateByOneYear() {
		*this = decreaseDateByOneYear(*this);
	};
	static clsDate decreaseDateByXYear(clsDate date, short years)
	{
		date._year -= years;
		return date;
	}
	void decreaseDateByXYear(short years) {
		*this = decreaseDateByXYear(*this, years);
	};
	static clsDate decreaseDateByOneDecade(clsDate date)
	{
		date._year -= 10;
		return date;
	}
	void decreaseDateByOneDecade() {
		*this = decreaseDateByOneDecade(*this);
	};
	static clsDate decreaseDateByXDecade(clsDate date, short decades)
	{
		date._year -= (10 * decades);
		return date;
	}
	void decreaseDateByXDecade(short decades) {
		*this = decreaseDateByXDecade(*this, decades);
	};
	static clsDate decreaseDateByOneCentury(clsDate date)
	{
		date._year -= 100;
		return date;
	}
	void decreaseDateByOneCentury() {
		*this = decreaseDateByOneCentury(*this);
	};
	static clsDate decreaseDateByOneMillennium(clsDate date)
	{
		date._year -= 1000;
		return date;
	}
	void decreaseDateByOneMillennium() {
		*this = decreaseDateByOneMillennium(*this);
	};
	static int calculateAgeInDays(clsDate  date) {
		return getDifferenceDays(date, getSystemDate(), true);
	};

	static void printHeader(short& month) {
		cout << "\n" << clsUtils::generateTabs(2);
		cout << clsUtils::generateLine(15) << getMonthName(month) << clsUtils::generateLine(15) << "\n\n";
		cout << clsUtils::generateTabs(2);
		cout << setw(3) << getWeekDayName(0) << "  ";
		cout << setw(3) << getWeekDayName(1) << "  ";
		cout << setw(3) << getWeekDayName(2) << "  ";
		cout << setw(3) << getWeekDayName(3) << "  ";
		cout << setw(3) << getWeekDayName(4) << "  ";
		cout << setw(3) << getWeekDayName(5) << "  ";
		cout << setw(3) << getWeekDayName(6) << "  ";
		cout << endl;
	};
	static void printFooter() {
		cout << "\n" << clsUtils::generateTabs(2);
		cout << clsUtils::generateLine(18) << clsUtils::generateLine(15) << "\n\n";
	}
	static void printBody(short& year, short& month) {
		short firstDay = getOrderWeekDayOfDate(1, month, year);
		short countMonthDays = countDaysInMonth(year, month);
		short currentDay = 1;

		cout << clsUtils::generateTabs(2);
		for (short i = 0;currentDay <= countMonthDays;i++) {
			if (i >= firstDay) {
				cout << setw(3) << currentDay << "  ";
				currentDay++;
			}
			else {
				cout << setw(3) << " " << "  ";
			}

			if ((i + 1) % 7 == 0) {
				cout << endl;
				cout << clsUtils::generateTabs(2);
			}
		}
	}
	static void printMonthCalendar(short year, short month) {
		printHeader(month);
		printBody(year, month);
		printFooter();
	};
	void printMonthCalendar() {
		printHeader(_month);
		printBody(_year, _month);
		printFooter();
	};
	static void printYearCalendar(short year) {
		cout << clsUtils::generateTabs(2) << clsUtils::generateLine(33, '=') << "\n";
		cout << clsUtils::generateTabs(12) << "Calendar - " << year << "\n";
		cout << clsUtils::generateTabs(2) << clsUtils::generateLine(33, '=') << "\n";
		for (short i = 1;i <= 12;i++) {
			printMonthCalendar(year, i);
		};
	};
	void printYearCalendar() {
		cout << clsUtils::generateTabs(2) << clsUtils::generateLine(33, '=') << "\n";
		cout << clsUtils::generateTabs(12) << "Calendar - " << _year << "\n";
		cout << clsUtils::generateTabs(2) << clsUtils::generateLine(33, '=') << "\n";
		for (short i = 1;i <= 12;i++) {
			printMonthCalendar(_year, i);
		};
	};
	static clsDate readDate() {
		clsDate date;
		bool first = true;
		do {
			if (!first) cout << "\nWrong entering please reenter the date :\n";else first = false;
			date._day = clsInputValidate::readNumberMsg("Please enter a day :");
			date._month = clsInputValidate::readNumberMsg("Please enter a month :");
			date._year = clsInputValidate::readPositiveNumberMsg("Please enter a year :");
			cout << "\n";
		} while (!isValidDate(date));

		return date;
	}
};