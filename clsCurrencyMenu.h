#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrenciesList.h"
class clsCurrencyMenu : protected clsScreen
{
private:
	enum enCurrencyOptions {  enListCurrencies=1,enFindCurrency=2,enUpdateRate=3,enCalculator=4,enMainMenu = 5 };

	static enCurrencyOptions _ReadCurrencyOption() {
		return (enCurrencyOptions)clsInputValidate::readNumberBetween(1, 5, "Choose what do you want to do? [1,5]");
	}
	static void _GoBackToCurrencyMenu() {
		cout << "\nPress any key to go back to Currency Exchange Menu...\n";
		system("pause>0");
		ShowCurrencyMenu();
	};
	static void _ShowListCurrencies() { clsCurrenciesList::ShowCurrenciesScreen(); }
	static void _ShowFindCurrency() { cout << "Find Currency will be here\n"; }
	static void _ShowUpdateRate() { cout << "Update Rate will be here\n"; }
	static void _ShowCalculator() { cout << "Currency Calculator will be here\n"; }

	static void _PerfromTransactionsMenuOption(enCurrencyOptions CurrencyOption)
	{
		switch (CurrencyOption)
		{
		case enCurrencyOptions::enListCurrencies:
			system("cls");
			_ShowListCurrencies();
			_GoBackToCurrencyMenu();
			break;
		case enCurrencyOptions::enFindCurrency:
			system("cls");
			_ShowFindCurrency();
			_GoBackToCurrencyMenu();
			break;
		case enCurrencyOptions::enUpdateRate:
			system("cls");
			_ShowUpdateRate();
			_GoBackToCurrencyMenu();
			break;
		case enCurrencyOptions::enCalculator:
			system("cls");
			_ShowCalculator();
			_GoBackToCurrencyMenu();
			break;
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
		cout << left << clsDrawer::generateTabs(40) << "[1] List Currencies.\n";
		cout << left << clsDrawer::generateTabs(40) << "[2] Find Currency.\n";
		cout << left << clsDrawer::generateTabs(40) << "[3] Update Rate.\n";
		cout << left << clsDrawer::generateTabs(40) << "[4] Currency Calculator.\n";
		cout << left << clsDrawer::generateTabs(40) << "[5] Main Menu.\n";
		cout << left << clsDrawer::generateTabs(35) << clsDrawer::generateLine(60, '=') << "\n";

		_PerfromTransactionsMenuOption(_ReadCurrencyOption());
	}
};