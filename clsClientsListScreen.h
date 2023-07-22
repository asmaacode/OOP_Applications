#pragma once
#include"clsBankClient.h"
#include"clsDrawer.h"
#include"clsScreen.h"
#include<iomanip>
using namespace std;
class clsClientsListScreen : protected clsScreen
{
private:
	static void _PrintClientsListHeader() {
		cout << "|" << left << setw(20) << "Account Number";
		cout << "|" << left << setw(25) << "Client Name";
		cout << "|" << left << setw(15) << "Phone";
		cout << "|" << left << setw(30) << "Email";
		cout << "|" << left << setw(10) << "Pin Code";
		cout << "|" << left << setw(10) << "Balance" << endl;
		cout << clsDrawer::generateLine(120) << endl;
	}
	static void _PrintClient(clsBankClient& Client) {
		cout << "|" << left << setw(20) << Client.AccountNumber;
		cout << "|" << left << setw(25) << Client.FullName();
		cout << "|" << left << setw(15) << Client.Phone;
		cout << "|" << left << setw(30) << Client.Email;
		cout << "|" << left << setw(10) << Client.PinCode;
		cout << "|" << left << setw(10) << to_string(Client.AccountBalance) << endl;
	}
public:
	static void ShowClientsList() {
		clsScreen::_DrawScreenHeader("Clients List","");
		_PrintClientsListHeader();
		vector<clsBankClient>VClients = clsBankClient::GetClientsList();
		if (VClients.size() > 0) {
			for (clsBankClient Client : VClients)
				_PrintClient(Client);
			cout << clsDrawer::generateLine(120) << endl;
			cout << "(" << VClients.size() << ") Clients" << endl;
		}
		else {
			cout << "There is no client in the system yet! \n";
		}
	}
};

