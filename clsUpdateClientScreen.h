#pragma once
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"

class clsUpdateClientScreen : protected clsScreen
{
public:
	static void UpdateClient() {
		clsScreen::_DrawScreenHeader("Update Client", "");
		string AccountNumber = clsInputValidate::readText(" \n");
		while (AccountNumber == "") {
			AccountNumber = clsInputValidate::readText("\nPlease enter the account number you want to update:");
		}
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "Sorry! The Account number does not exist ! \n";
			AccountNumber = clsInputValidate::readText("\nPlease enter the account number you want to update:");
		}
		clsBankClient CurrentClient = clsBankClient::Find(AccountNumber);
		cout << "The founded client  :\n";
		CurrentClient.Print();
		clsInputValidate::EnterClientData(CurrentClient);
		switch (CurrentClient.Save())
		{
		case clsBankClient::svSuccess:
			cout << "Account Updated Successfully !";
			CurrentClient.Print();
			break;
		case clsBankClient::svFailedEmptyClient:
			cout << "\nError account was not saved because it's Empty";
			break;
		}
	}
};

