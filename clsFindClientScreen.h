#pragma once
#include"clsInputValidate.h"
#include"clsScreen.h"

class clsFindClientScreen:protected clsScreen
{
public:
	static void FindClient() {
		clsScreen::_DrawScreenHeader("Find Client", "");
		string AccountNumber = clsInputValidate::readText(" \n");
		while (AccountNumber == "") {
			AccountNumber = clsInputValidate::readText("\nPlease enter the account number you want to find:");
		}
		if (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "Sorry! The Account number does not exist ! \n";
			return;
		}
		clsBankClient CurrentClient = clsBankClient::Find(AccountNumber);
		cout << "The founded client  :\n";
		CurrentClient.Print();
	}
};

