#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
class clsCurrenciesList:protected clsScreen
{
private:
	static void _PrintCurrenciesListHeader() {
		cout << "|" << left << setw(35) << "Country";
		cout << "|" << left << setw(25) << "Code";
		cout << "|" << left << setw(35) << "Name";
		cout << "|" << left << setw(15) << "Rate"<< endl;
		cout << clsDrawer::generateLine(120) << endl;
	}
	static void _PrintCurrencies(clsCurrency& Currency) {
		cout << "|" << left << setw(35) << Currency.Country();
		cout << "|" << left << setw(25) << Currency.CurrencyCode();
		cout << "|" << left << setw(35) << Currency.CurrencyName();
		cout << "|" << left << setw(15) <<  to_string(Currency.Rate()) << endl;
	}
public:
	static void ShowCurrenciesScreen() {
		vector<clsCurrency>vCurrency = clsCurrency::GetCurrenciesList();
		string Total = to_string(vCurrency.size());
		clsScreen::_DrawScreenHeader("Currencies List", "(" + Total + ")Currency");
		_PrintCurrenciesListHeader();

		if (vCurrency.size() > 0) {
			for (clsCurrency Currency : vCurrency)
				_PrintCurrencies(Currency);
			cout << clsDrawer::generateLine(120) << endl;
		}
		else {
			cout << "There is no currency in the system yet! \n";
		}

	}
};

