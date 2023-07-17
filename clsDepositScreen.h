#pragma once
#include<string>
#include"clsScreen.h"
#include"clsInputValidate.h"
using namespace std;
class clsDepositScreen : protected clsScreen
{
private:
	static string _ReadAccountNumber(string msg = "Please enter the account number to deposit:")
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

public:
	static void ShowDepositScreen() {
		_DrawScreenHeader("Deposit Screen", "");
		
		string AccountNumber = _ReadAccountNumber("Please enter the account number to deposit:\n");
		clsBankClient CurrentClient = clsBankClient::Find(AccountNumber);
		CurrentClient.Print();
		float Amount = clsInputValidate::readFltNumber("\nPlease enter amount :");
		
		if (CurrentClient.Deposit(Amount))
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

