#pragma once
#include "clsDate.h"
class clsPeriod
{
private:
	clsDate fromDate;clsDate toDate;
public:
	clsPeriod()
	{
		
	};
	clsPeriod(clsDate fromDate, clsDate toDate)
	{
		this->fromDate = fromDate;
		this->toDate = toDate;
	};
	static bool isPeriodsOverlap(clsPeriod period1, clsPeriod period2) {
		return(clsDate::compareDates(period2.toDate, period1.fromDate) != clsDate::enCompareDate::Before
			&& clsDate::compareDates(period2.fromDate, period1.toDate) != clsDate::enCompareDate::After);
	};
	bool isPeriodsOverlap(clsPeriod period2) {
		return isPeriodsOverlap(*this, period2);
	};
	static bool isDateInPeriod(clsPeriod period, clsDate date) {
		return (clsDate::compareDates(period.fromDate, date) != clsDate::enCompareDate::Before ||
			clsDate::compareDates(date, period.toDate) != clsDate::enCompareDate::After);
	};
	bool isDateInPeriod(clsDate date) {
		return isDateInPeriod(*this, date);
	};
	static int periodLength(clsPeriod period, bool includingEndDay = false) {
		return clsDate::getDifferenceDays(period.fromDate, period.toDate, includingEndDay);
	};
	int periodLength(bool includingEndDay = false) {
		return periodLength(*this, includingEndDay);
	};
	void Print()
	{
		cout << "Period Start: ";
		fromDate.print();
		cout << "Period End: ";
		toDate.print();
	};
	static clsPeriod readPeriod() {
		clsPeriod period;
		bool first = true;
		do {
			if (!first) cout << "\nWrong entering please reenter the period :\n";else first = false;
			cout << "From Date:\n";
			period.fromDate = clsDate::readDate();
			cout << "To Date:\n";
			period.toDate = clsDate::readDate();
		} while (clsDate::isDate1AfterDate2(period.fromDate, period.toDate) && !clsDate::isDate1EqualDate2(period.fromDate, period.toDate));
		return period;
	};
};

