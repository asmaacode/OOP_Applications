#include<iostream> 
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;

void EnterClientData(clsBankClient& Client) {
	Client.FirstName = clsInputValidate::readText("Please enter the First Name :");
	Client.LastName = clsInputValidate::readText("Please enter the Last Name:");
	Client.Email = clsInputValidate::readText("Please enter the Email :");
	Client.Phone = clsInputValidate::readText("Please enter the Phone :");
	Client.PinCode = clsInputValidate::readText("Please enter the Pin Code :");
	Client.AccountBalance = clsInputValidate::readFltNumber("Please enter the Balance Number :");
}
void UpdateClient() {
	string AccountNumber = clsInputValidate::readText("Please enter the account number you want to update:");

	while (!clsBankClient::IsClientExist(AccountNumber)) {
		cout << "Sorry! The Account number does not exist ! \n";
		AccountNumber = clsInputValidate::readText("Please enter the account number:");
	}

	clsBankClient CurrentClient = clsBankClient::Find(AccountNumber);
	cout << "The founded client  :\n";
	CurrentClient.Print();

	EnterClientData(CurrentClient);

	switch (CurrentClient.Save())
	{
	case clsBankClient::svSuccess:
		cout << "Account Updated Successfully !";
		break;
	case clsBankClient::svFailedEmptyClient:
		cout << "\nError account was not saved because it's Empty";
		break;
	}
}
void AddNewClient() {
	string AccountNumber = clsInputValidate::readText("Please enter the new account number :");

	while (clsBankClient::IsClientExist(AccountNumber)) {
		cout << "Sorry! The Account number already exists ! \n";
		AccountNumber = clsInputValidate::readText("Please enter the new account number :");
	}
	clsBankClient CurrentClient = clsBankClient::GetNewClientObject(AccountNumber);
	EnterClientData(CurrentClient);

	switch (CurrentClient.Save())
	{
	case clsBankClient::svSuccess:
		cout << "The new account added successfully !";
		break;
	case clsBankClient::svFailedEmptyClient:
		cout << "\nError account was not saved because it's Empty";
		break;
	case clsBankClient::svFailedAddExistsClient:
		cout << "\nError account already Exists";
		break;
	}
}

int    main() {
	AddNewClient();
	system("pause>0");
	return 0;
};