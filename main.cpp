//initiate an inner-class using constructor
#include<iostream> 
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;

void EnterUpdatedClientData(clsBankClient& Client) {
	Client.FirstName = clsInputValidate::readText("Please enter the First Name :");
	Client.LastName = clsInputValidate::readText("Please enter the Last Name:");
	Client.Email = clsInputValidate::readText("Please enter the Email :");
	Client.Phone = clsInputValidate::readText("Please enter the Phone :");
	Client.PinCode = clsInputValidate::readText("Please enter the Pin Code :");
	Client.AccountBalance = clsInputValidate::readFltNumber("Please enter the Balance Number :");
}
void UpdateClient() {
	string AccountNumber = clsInputValidate::readText("Please enter the account number:");

	while (!clsBankClient::IsClientExist(AccountNumber)) {
		cout << "Sorry! The Account number does not exist ! \n";
		AccountNumber = clsInputValidate::readText("Please enter the account number:");
	}

	clsBankClient CurrentClient = clsBankClient::Find(AccountNumber);
	cout << "The founded client  :\n";
	CurrentClient.Print();

	EnterUpdatedClientData(CurrentClient);
	
	switch (CurrentClient.Save())
	{
	case clsBankClient::enSuccess:
		cout << "Account Updated Successfully !";
		break;
	case clsBankClient::enEmptyFailed:
		cout << "\nError account was not saved because it's Empty"; 
		break;
	}
}

int    main() {
	UpdateClient();
	system("pause>0");
	return 0;
};