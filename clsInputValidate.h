#pragma once
#include <string>
#include "clsDate.h"
using namespace std;
class clsInputValidate
{
public:
	static bool isNumberBetween(short number, short from, short to)
	{
		return (number >= from && number <= to);
	};
	static bool isNumberBetween(int number, int from, int to)
	{
		return  (number >= from && number <= to);
	};
	static bool isNumberBetween(float number, float from, float to)
	{
		return (number >= from && number <= to);
	};
	static bool isNumberBetween(double number, double from, double to)
	{
		return (number >= from && number <= to);
	};
	static bool doYouQuestion(string msg="") {
		char answer = 'N';
		cout << msg << "[Y / N]";
		cin >> answer;
		return ((answer == 'Y' || answer == 'y') ? true : false);
	};
	static int readNumber(string msg="") {
		int userNumber = 0;
		cin >> userNumber;
		while (cin.fail())
		{
			// Explain error
			cout << msg;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> userNumber;
		}
		return  userNumber;
	}
	static int readNumberBetween(int from, int to, string msg = "ERROR: A Number must be entered:\n") {
		int number = 0;
		do {
			cout << msg;
			number = readNumber();
		} while (isNumberBetween(number,from,to));
		return number;
	};
	static double readDblNumber(string msg = "") {
		double userNumber = 0;
		cin >> userNumber;
		while (cin.fail())
		{
			// Explain error
			cout << msg;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> userNumber;
		}
		return  userNumber;
	}
	static double readDblNumberBetween(double from, double to, string msg = "ERROR: A Number must be entered:\n") {
		double number = 0;
		do {
			cout << msg;
			number = readNumber();
		} while (isNumberBetween(number, from, to));
		return number;
	};
	static string readText(string message) {
		string txt = "";
		cout << message;
		getline(cin, txt);
		return  txt;
	}
	static string readTextNoWhiteSpace(string message="") {
		string txt = "";
		cout << message;
		cin >> txt;
		return  txt;
	}
	static char readChar(string message) {
		char txt = ' ';
		cout << message << "\n";
		cin >> txt;
		return  txt;
	}
	static bool isDateBetween(clsDate date, clsDate date1, clsDate date2) {
		return (clsDate::compareDates(date, date1) != clsDate::enCompareDate::Before &&
			clsDate::compareDates(date, date2) != clsDate::enCompareDate::After)
			||
			(clsDate::compareDates(date, date2) != clsDate::enCompareDate::Before &&
				clsDate::compareDates(date, date1) != clsDate::enCompareDate::After);
	};
	static bool isValideDate(clsDate Date)
	{
		return	clsDate::isValidDate(Date);
	};
	static clsDate readDate() {
		clsDate date;
		bool first = true;
		do {
			if (!first) cout << "\nWrong entering please reenter the date :\n";else first = false;
			date.setDay(readNumber("Please enter a day :"));
			date.setMonth(readNumber("Please enter a month :"));
			date.setYear(readNumber("Please enter a year :"));
			cout << "\n";
		} while (!clsDate::isValidDate(date));

		return date;
	};
};

