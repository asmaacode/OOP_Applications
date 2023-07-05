#pragma once
#include"clsScreen.h"
#include"clsInputValidate.h"
class clsDeleteClientScreen : protected clsScreen
{
public:
	static void DeleteClient() {
		clsScreen::_DrawScreenHeader("Delete Client", "");

		string AccountNumber = clsInputValidate::readText(" \n");
		while (AccountNumber == "") {
			AccountNumber = clsInputValidate::readText("\nPlease enter the account number you want to delete:");
		}
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "Sorry! The Account number does not exist ! \n";
			AccountNumber = clsInputValidate::readText("\nPlease enter the account number you want to delete:");
		}

		clsBankClient CurrentClient = clsBankClient::Find(AccountNumber);
		CurrentClient.Print();
		if (clsInputValidate::doYouQuestion("Do you want to delete this account ?"))
			if (CurrentClient.Delete()) {
				cout << "The account deleted successfully \n";
				//CurrentClient.Print();
			}
			else {
				cout << "The account was not deleted \n";
			}
	}
};

