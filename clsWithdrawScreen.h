#pragma once
#include<string>
#include"clsScreen.h"
#include"clsInputValidate.h"

class clsWithdrawScreen : protected clsScreen
{
private:
	static string _ReadAccountNumber(string msg = "Please enter the account number to withdraw ")
	{
		string AccountNumber = clsInputValidate::readText(" \n");
		while (AccountNumber == "") {
			cout << " \n";
			AccountNumber = clsInputValidate::readText(msg);
		}
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "Sorry! The Account number does not exist ! \n";
			cout << " \n";
			AccountNumber = clsInputValidate::readText(msg);
		}

		return AccountNumber;
	}
	static float _ReadAmount(clsBankClient Client)
	{
		float Amount;
		Amount = clsInputValidate::readFltNumber("\nEnter amount? ");
		while (Amount > Client.AccountBalance)
		{
			Amount = clsInputValidate::readDblNumber("\nAmount exceeds the available balance, Enter another amount ?");
		}
		return Amount;
	}
public:
	static void ShowWithdrawScreen() {
		_DrawScreenHeader("Withdraw Screen", "");
		string AccountNumber = _ReadAccountNumber("Please enter the account number to withdraw: ");
		clsBankClient CurrentClient = clsBankClient::Find(AccountNumber);
		CurrentClient.Print();

		float Amount = _ReadAmount(CurrentClient);

		if (CurrentClient.Withdraw(Amount))
		{
			cout << "\nThe transaction performed successfully.\n";
			cout << "\nNew Balances is" << CurrentClient.AccountBalance << endl;
		}
		else
		{
			cout << "\nWithdraw Faild \n";
		}
	}
};

