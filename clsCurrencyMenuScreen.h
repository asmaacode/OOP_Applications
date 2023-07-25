#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"
class clsCurrencyMenuScreen : protected clsScreen
{
private:
	enum enCurrencyOptions { enListCurrencies = 1, enFindCurrency = 2, enUpdateRate = 3, enCalculator = 4, enMainMenu = 5 };

	static enCurrencyOptions _ReadCurrencyOption() {
		return (enCurrencyOptions)clsInputValidate::readNumberBetween(1, 5, "Choose what do you want to do? [1,5]");
	}
	static void _GoBackToCurrencyMenu() {
		cout << "\nPress any key to go back to Currency Exchange Menu...\n";
		system("pause>0");
		ShowCurrencyMenu();
	};
	static void _ShowListCurrencies() { clsCurrenciesListScreen::ShowCurrenciesScreen(); }
	static void _ShowFindCurrency() { clsFindCurrencyScreen::ShowFindCurrencyScreen(); }
	static void _ShowUpdateRate() { clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRate(); }
	static void _ShowCalculator() { clsCurrencyCalculatorScreen::ShowCurrencyCalculator(); }

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
		case enCurrencyOptions::enMainMenu: {}
		}
	}
public:
	static void ShowCurrencyMenu() {
		system("cls");
		_DrawScreenHeader("Currency Exchange Main Screen", "");
		cout << "\n";
		cout << left << clsDrawer::generateTabs(40) << clsDrawer::generateLine(40, '=') << "\n";
		cout << left << clsDrawer::generateTabs(50) << "Currency Exchange Menu\n";
		cout << left << clsDrawer::generateTabs(40) << clsDrawer::generateLine(40, '=') << "\n";
		cout << left << clsDrawer::generateTabs(50) << "[1] List Currencies.\n";
		cout << left << clsDrawer::generateTabs(50) << "[2] Find Currency.\n";
		cout << left << clsDrawer::generateTabs(50) << "[3] Update Rate.\n";
		cout << left << clsDrawer::generateTabs(50) << "[4] Currency Calculator.\n";
		cout << left << clsDrawer::generateTabs(50) << "[5] Main Menu.\n";
		cout << left << clsDrawer::generateTabs(40) << clsDrawer::generateLine(40, '=') << "\n";

		_PerfromTransactionsMenuOption(_ReadCurrencyOption());
	}
};