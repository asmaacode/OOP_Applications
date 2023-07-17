#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"

class clsTransferScreen : protected clsScreen
{
private:
	static void _Print(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n_________________________";
		cout << "\nFull Name: " << Client.FullName();
		cout << "\n Account Number:" << Client.AccountNumber;
		cout << "\n Balance:" << Client.AccountBalance;
		cout << "\n_________________________\n";
	}
	static string _ReadAccountNumber(string msg="Please enter the account number to transfer ")
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

	static float _ReadAmount(clsBankClient FromClient)
	{
		float Amount;
		Amount = clsInputValidate::readFltNumber("\nEnter Transfer Amount? ");
		while (Amount > FromClient.AccountBalance)
		{
			Amount = clsInputValidate::readDblNumber("\nAmount Exceeds the available Balance, Enter another Amount ?");
		}
		return Amount;
	}

public:
	static void ShowTransferScreen() {
		clsScreen::_DrawScreenHeader("Transfer Screen", "");

		string FromAccount = _ReadAccountNumber("Please enter the account number to transfer From: ");
		clsBankClient FromClient = clsBankClient::Find(FromAccount);

		string ToAccount = _ReadAccountNumber("Please enter the account number to transfer To: ");
		clsBankClient ToClient = clsBankClient::Find(ToAccount);

		_Print(FromClient);
		_Print(ToClient);

		float Amount = _ReadAmount(FromClient);
		if (!clsInputValidate::doYouQuestion("Are you sure you want to perform this operation ?")) {
			return;
		}

		if (FromClient.Transfer(Amount, ToClient))
		{
			cout << "\nThe transaction performed successfully.\n";
		}
		else
		{
			cout << "\nTransfer Faild \n";
		}

		_Print(FromClient);
		_Print(ToClient);
	}
};

