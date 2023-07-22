#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"

class clsCurrencyMenu : protected clsScreen
{
private:
	enum enCurrencyOptions {  enMainMenu = 5 };

	static enCurrencyOptions _ReadCurrencyOption() {
		return (enCurrencyOptions)clsInputValidate::readNumberBetween(1, 5, "Choose what do you want to do? [1,5]");
	}
	static void _GoBackToTrancationMenu() {
		cout << "\nPress any key to go back to Transactions Menu...\n";
		system("pause>0");
		ShowCurrencyMenu();
	};
	static void _PerfromTransactionsMenuOption(enCurrencyOptions CurrencyOption)
	{
		switch (CurrencyOption)
		{
		
		case enCurrencyOptions::enMainMenu: {

		}
		}
	}
public:
	static void ShowCurrencyMenu() {
		system("cls");
		_DrawScreenHeader("Currency Exchange Menu", "");
		cout << "\n";
		cout << left << clsDrawer::generateTabs(35) << clsDrawer::generateLine(60, '=') << "\n";
		cout << left << clsDrawer::generateTabs(50) << "Currency Exchange Menu\n";

		cout << left << clsDrawer::generateTabs(40) << "[5] MainMenu.\n";
		cout << left << clsDrawer::generateTabs(35) << clsDrawer::generateLine(60, '=') << "\n";

		_PerfromTransactionsMenuOption(_ReadCurrencyOption());
	}
};