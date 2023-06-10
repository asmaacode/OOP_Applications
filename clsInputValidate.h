#pragma once
#include <string>
#include "clsDate.h"
using namespace std;
class clsInputValidate
{
public:
	static bool doYouQuestion(string msg="") {
		char answer = 'N';
		cout << msg << "[Y / N]";
		cin >> answer;
		return ((answer == 'Y' || answer == 'y') ? true : false);
	};
	static int readNumber() {
		int userNumber = 0;
		cin >> userNumber;
		while (cin.fail())
		{
			// Explain error
			cout << "ERROR: A Number must be entered:\n";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> userNumber;
		}
		return  userNumber;
	}
	static float readFloatNumber() {
		float userNumber = 0;
		while (!(cin >> userNumber))
		{
			// Explain error
			cout << "ERROR: A Number must be entered:\n";
			cin.clear();
			cin.ignore(132, '\n');
		}
		return  userNumber;
	}
	static int readPositiveNumber() {
		int positiveNumber = 0;
		do {
			cout << "Please enter a number greater than zero :\n";
			positiveNumber = readNumber();
		} while (positiveNumber <= 0);

		return positiveNumber;
	}
	static int readPositiveNumberMsg(string msg="") {
		int positiveNumber = 0;
		do {
			cout << msg;
			positiveNumber = readNumber();
		} while (positiveNumber < 0);

		return positiveNumber;
	}
	static int readNumberMsg(string msg) {
		int number = 0;
		cout << msg << " ";
		number = readNumber();
		return number;
	}
	static float readFloatNumberMsg(string msg="") {
		float number = 0.0;
		cout << msg;
		number = readFloatNumber();
		return number;
	}
	static string readText(string message) {
		string txt = "";
		cout << message;
		getline(cin, txt);
		return  txt;
	}
	static string readTextWithoutWs(string message="") {
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
	static int readNumberInRangeMsg(string msg, int from, int to) {
		int number = 0;
		do {
			cout << msg;
			number = readNumber();
		} while (number > to || number < from);

		return number;
	};
	static bool isDateBetween(clsDate date, clsDate date1, clsDate date2) {
		return clsPeriod::isDateInPeriod(clsPeriod(date1, date2), date) || clsPeriod::isDateInPeriod(clsPeriod(date2, date1), date);
	};
};

