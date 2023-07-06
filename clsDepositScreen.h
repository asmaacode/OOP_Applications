#pragma once
#include<string>
#include"clsScreen.h"
#include"clsInputValidate.h"
using namespace std;
class clsDepositScreen : protected clsScreen
{
public:
	static void ShowDepositScreen() {
		_DrawScreenHeader("Deposit Screen", "");
		string AccountNumber = clsInputValidate::readText(" \n");
		while (AccountNumber == "") {
			AccountNumber = clsInputValidate::readText("\nPlease enter the account number:");
		}
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "Sorry! The Account number does not exist ! \n";
			AccountNumber = clsInputValidate::readText("\nPlease enter the account number:");
		}
		clsBankClient CurrentClient = clsBankClient::Find(AccountNumber);
		CurrentClient.Print();
		float Amount = clsInputValidate::readFltNumber("\nPlease enter amount :");
		CurrentClient.Deposit(Amount);
		switch (CurrentClient.Save())
		{
		case clsBankClient::svSuccess:
			cout << "\nThe transaction performed successfully.\n";
			cout << "\nNew Balances is" << CurrentClient.AccountBalance << endl;
			break;
		case clsBankClient::svFailedEmptyClient:
			cout << "\nError transaction was not performend because client is Empty.\n";
			break;
		}
	}
};

