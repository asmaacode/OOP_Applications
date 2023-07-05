#pragma once
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsDrawer.h"
#include"clsScreen.h"
#include<iomanip>
using namespace std;
class clsAddNewClientScreen : protected clsScreen
{
public:
	static void AddNewClient() {
		clsScreen::_DrawScreenHeader("Add New Client", "");
		string AccountNumber = clsInputValidate::readText(" \n");
		while (AccountNumber == "" ) {
			AccountNumber = clsInputValidate::readText("\nPlease enter the new account number :");
		}
		while (clsBankClient::IsClientExist(AccountNumber)) {
			cout << "Sorry! The Account number already exists ! \n";
			AccountNumber = clsInputValidate::readText("Please enter the new account number :");
		}
		clsBankClient CurrentClient = clsBankClient::GetNewClientObject(AccountNumber);
		clsInputValidate::EnterClientData(CurrentClient);
		switch (CurrentClient.Save())
		{
		case clsBankClient::svSuccess:
			cout << "The new account added successfully !\n";
			CurrentClient.Print();
			break;
		case clsBankClient::svFailedEmptyClient:
			cout << "\nError account was not saved because it's Empty.\n";
			break;
		case clsBankClient::svFailedAddExistsClient:
			cout << "\nError account already Exists.\n";
			break;
		}
	}
};

