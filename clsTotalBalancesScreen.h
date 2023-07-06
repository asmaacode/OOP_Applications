#pragma once
#include"clsBankClient.h"
#include"clsDrawer.h"
#include"clsUtils.h"
#include"clsScreen.h"
#include<iomanip>
class clsTotalBalancesScreen : protected clsScreen
{
private:
	static void _PrintTotalBalancesHeader() {
		cout << "|" << left << setw(25) << "Account Number";
		cout << "|" << left << setw(35) << "Client Name";
		cout << "|" << left << setw(10) << "Balance" << endl;
		cout << clsDrawer::generateLine(120) << endl;
	}
	static void _PrintTotalBalance(clsBankClient& Client) {
		cout << "|" << left << setw(25) << Client.AccountNumber;
		cout << "|" << left << setw(35) << Client.FullName();
		cout << "|" << left << setw(10) << to_string(Client.AccountBalance) << endl;
	}
public:
	static void ShowTotalBalances() {
		clsScreen::_DrawScreenHeader("Total Balances List", "");
		_PrintTotalBalancesHeader();
		vector<clsBankClient>VClients = clsBankClient::GetClientsList();
		if (VClients.size() > 0) {
			for (clsBankClient Client : VClients)
				_PrintTotalBalance(Client);
			cout << clsDrawer::generateLine(120) << endl;
			double Total = clsBankClient::GetTotalBalances();
			cout << "Total Balances = " << Total << endl;
			cout << "( " << clsUtils::NumberToText(int(Total)) << ")\n";
		}
		else {
			cout << "There is no client in the system yet! \n";
		}
	}
};

