#pragma once
#include <string>
#include "clsBankClient.h"
#include "clsUser.h"
#include "clsDate.h"

class clsInputValidate_Optimized
{
public:
	template <typename T> static T isNumberBetween(T number, T from, T to) {
		return (number >= from && number <= to);
	};

	static bool doYouQuestion(string msg = "") {
		char answer = 'N';
		cout << msg << "[Y / N]";
		cin >> answer;
		return ((answer == 'Y' || answer == 'y') ? true : false);
	};
	template <typename T>static T readNumber(string msg = "") {
		int Number;
		cout << msg;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		return Number;
	}
	template<typename T> static T readNumberBetween(T from, T to, string msg = "ERROR: A Number must be entered:\n") {
		T number = 0;
		do {
			cout << msg;
			number = readNumber();
		} while (!isNumberBetween<T>(number, from, to));
		return number;
	};
	template <typename T>static T readString(T message) {
		T txt;
		cout << message;
		cin >> txt;
		return  txt;
	}
	static string readText(string message) {
		string txt = "";
		cout << message;
		getline(cin, txt);
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
			date.setDay(readNumber<int>("Please enter a day :"));
			date.setMonth(readNumber<int>("Please enter a month :"));
			date.setYear(readNumber<int>("Please enter a year :"));
			cout << "\n";
		} while (!clsDate::isValidDate(date));

		return date;
	};
	static void EnterClientData(clsBankClient& Client) {
		Client.FirstName = clsInputValidate::readText("Please enter the First Name :");
		Client.LastName = clsInputValidate::readText("Please enter the Last Name:");
		Client.Email = clsInputValidate::readText("Please enter the Email :");
		Client.Phone = clsInputValidate::readText("Please enter the Phone :");
		Client.PinCode = clsInputValidate::readText("Please enter the Pin Code :");
		Client.AccountBalance = clsInputValidate::readNumber<float>("Please enter the Balance Number :");
	}
	static void EnterUserData(clsUser& User) {
		User.FirstName = readText("Please enter the First Name :");
		User.LastName = readText("Please enter the Last Name:");
		User.Email = readText("Please enter the Email :");
		User.Phone = readText("Please enter the Phone :");
		User.Password = readText("Please enter the Password :");
		User.Rights = ReadUserRights();
	}

	static int ReadUserRights() {
		if (doYouQuestion("Do you want to give this user full access ?"))
			return -1;
		cout << "Do you want to give access to :\n";
		int rights = 0;
		if (doYouQuestion("Show Clients List ?"))rights += clsUser::enShowClients;
		if (doYouQuestion("Add New Client ?"))rights += clsUser::enAddNewClient;
		if (doYouQuestion("Delete Client ?"))rights += clsUser::enDeleteClient;
		if (doYouQuestion("Update Client ?"))rights += clsUser::enUpdateClient;
		if (doYouQuestion("Find Client ?"))rights += clsUser::enFindClient;

		if (doYouQuestion("Transactions ?"))
		{
			rights += clsUser::enTransactions;
		}
		if (doYouQuestion("Manage Users ?"))
		{
			rights += clsUser::enManageUsers;
		}
		if (doYouQuestion("Login Log List ?"))
		{
			rights += clsUser::enShowLoginLog;
		}
		if (doYouQuestion("Currency Exchange ?"))
		{
			rights += clsUser::enCurrencyExchange;
		}

		return rights;
	}
};

