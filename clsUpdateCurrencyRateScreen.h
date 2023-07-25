#pragma once
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"

class clsUpdateCurrencyRateScreen : protected clsScreen
{
public:
	static void ShowUpdateCurrencyRate() {
		clsScreen::_DrawScreenHeader("Update Currency Rate", "");
		string CurrencyCode = clsInputValidate::readTextNoWhiteSpace("\nPlease enter the Currency Code you want to update:");
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		if (Currency.IsEmpty())
		{
			cout << "\nCurrency was not found :-(\n";
		}
		else
		{
			Currency.Print();
			if (clsInputValidate::doYouQuestion("Are you sure you want to update this currency rate ?"))
			{
				Currency.UpdateRate(clsInputValidate::readFltNumber("Enter new rate :"));
				cout << "Currency Rate Updated Successfully!\n";
				Currency.Print();
			}
			return;
		}
	}
};

