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
void DeleteClient() {
	string AccountNumber = clsInputValidate::readText("Please enter the account number you want to delete :");

	while (!clsBankClient::IsClientExist(AccountNumber)) {
		cout << "Sorry! The Account number does not exist ! \n";
		AccountNumber = clsInputValidate::readText("Please reenter the account number you want to delete :");
	}
	clsBankClient CurrentClient = clsBankClient::Find(AccountNumber);
	CurrentClient.Print();
	if (clsInputValidate::doYouQuestion("Do you want to delete this account ?"))
		if (CurrentClient.Delete()) {
			cout << "The account deleted successfully \n";
			CurrentClient.Print();
		}
		else {
			cout << "The account was not deleted \n";
		}

}
void PrintClientsListHeader() {
	cout << clsDrawer::generateTabs(50) << "Clients List\n";
	cout << clsDrawer::generateLine(120) << endl;
	cout << "|" << left << setw(20) << "Account Number";
	cout << "|" << left << setw(25) << "Client Name";
	cout << "|" << left << setw(15) << "Phone";
	cout << "|" << left << setw(30) << "Email";
	cout << "|" << left << setw(10) << "Pin Code";
	cout << "|" << left << setw(10) << "Balance" << endl;
	cout << clsDrawer::generateLine(120) << endl;
}
void PrintClient(clsBankClient& Client) {
	cout << "|" << left << setw(20) << Client.AccountNumber;
	cout << "|" << left << setw(25) << Client.FullName();
	cout << "|" << left << setw(15) << Client.Phone;
	cout << "|" << left << setw(30) << Client.Email;
	cout << "|" << left << setw(10) << Client.PinCode;
	cout << "|" << left << setw(10) << to_string(Client.AccountBalance)<< endl;
}
void ShowClientsList() {
	PrintClientsListHeader();
	vector<clsBankClient>VClients = clsBankClient::GetClientsList();
	if (VClients.size() > 0) {
		for(clsBankClient Client:VClients)
			PrintClient(Client);
		cout << clsDrawer::generateLine(120) << endl;
		cout << "(" << VClients.size()<<") Clients" << endl;
	}
	else {
		cout << "There is no client in the system yet! \n";
	}
}

int    main() {
	ShowClientsList();
	system("pause>0");
	return 0;
};