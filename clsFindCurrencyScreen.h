#pragma once
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsCurrency.h"

class clsFindCurrencyScreen :protected clsScreen
{
private:
	static void _FindCurrencyByCode() {
		string CurrencyCode = clsInputValidate::readTextNoWhiteSpace("\nPlease enter the Currency Code you want to find:");
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		if (!Currency.IsEmpty())
		{
			Currency.Print();
		}
		else
		{
			cout << "\nCurrency was not found :-(\n";
		}
	}
	static void _FindCurrencyByCountry() {
		string Country = clsInputValidate::readTextNoWhiteSpace("\nPlease enter the Country you want to find:");
		clsCurrency Currency = clsCurrency::FindByCountry(Country);
		if (!Currency.IsEmpty())
		{
			Currency.Print();
		}
		else
		{
			cout << "\nCurrency was not found :-(\n";
		}
	}
public:
	static void ShowFindCurrencyScreen() {
		clsScreen::_DrawScreenHeader("Find Currency", "");
		short FindBy = clsInputValidate::readNumber("Find By: [1] Code or [2] Country ? ");
		if (FindBy == 1){
			_FindCurrencyByCode();
		}
		else{
			_FindCurrencyByCountry();
		}
	}
};

