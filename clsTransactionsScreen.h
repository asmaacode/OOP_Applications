#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
using namespace std;

class clsTransactionsScreen : protected clsScreen
{
private:
	enum enTransactionsOptions { enDeposit = 1, enWithdraw = 2, enTotalBalances = 3, enMainMenu = 4 };
	static void _ShowDepositeScreen() {
		clsDepositScreen::ShowDepositScreen();
	};
	static void _ShowWithdrawScreen() {
		clsWithdrawScreen::ShowWithdrawScreen();
	};
	static void _ShowTotalBalancesScreen() {
		clsTotalBalancesScreen::ShowTotalBalances();
	};
	static enTransactionsOptions _ReadTransactionOption() {
		return (enTransactionsOptions)clsInputValidate::readNumberBetween(1, 4, "Choose what do you want to do? [1,4]");
	}
	static void _GoBackToTrancationMenu() {
		cout << "\nPress any key to go back to Transactions Menu...\n";
		system("pause>0");
		ShowTransactionsMenu();
	};
	static void _PerfromTransactionsMenuOption(enTransactionsOptions TransactionOption)
	{
		switch (TransactionOption)
		{
		case enTransactionsOptions::enDeposit:
			system("cls");
			_ShowDepositeScreen();
			_GoBackToTrancationMenu();
			break;
		case enTransactionsOptions::enWithdraw:
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTrancationMenu();
			break;
		case enTransactionsOptions::enTotalBalances:
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTrancationMenu();
			break;
		case enTransactionsOptions::enMainMenu: {

		}
		}
	}
public:
	static void ShowTransactionsMenu() {
		system("cls");
		_DrawScreenHeader("Trancations Screen", "");
		cout << "\n";
		cout << left << clsDrawer::generateTabs(35) << clsDrawer::generateLine(40, '=') << "\n";
		cout << left << clsDrawer::generateTabs(50) << "Transactions Menu\n";
		cout << left << clsDrawer::generateTabs(35) << clsDrawer::generateLine(40, '=') << "\n";
		cout << left << clsDrawer::generateTabs(40) << "[1] Deposit.\n";
		cout << left << clsDrawer::generateTabs(40) << "[2] Withdraw.\n";
		cout << left << clsDrawer::generateTabs(40) << "[3] Total Balances.\n";
		cout << left << clsDrawer::generateTabs(40) << "[4] MainMenu.\n";
		cout << left << clsDrawer::generateTabs(35) << clsDrawer::generateLine(40, '=') << "\n";

		_PerfromTransactionsMenuOption(_ReadTransactionOption());
	}

};

