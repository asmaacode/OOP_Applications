#pragma once
#include "clsScreen.h"
#include "clsString.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
class clsCurrencyCalculatorScreen : protected clsScreen
{
private:
	static string _ReadFromCurrency() {
		return clsInputValidate::readTextNoWhiteSpace("Please enter currency 1 code :  ");
	}
	static string _ReadToCurrency() {
		return clsInputValidate::readTextNoWhiteSpace("Please enter currency 2 code :  ");
	}
	static float _ReadAmount() {
		return clsInputValidate::readFltNumber("Enter amount to exchange: ");
	}
	static void _PrintResult(float Amount, string FromCurrency, string ToCurrency, float ResultAmount) {
		cout << Amount << " " << FromCurrency << " = " << ResultAmount << " " << ToCurrency << "\n";
	}
public:
	static void ShowCurrencyCalculator() {
		_DrawScreenHeader("Currency Calculator", "");

		clsCurrency Currency1 = clsCurrency::FindByCode(_ReadFromCurrency());
		clsCurrency Currency2 = clsCurrency::FindByCode(_ReadToCurrency());
		float Amount = _ReadAmount();
		float Result;

		cout << "\n\nConvert From:";
		Currency1.Print();
		
		if (clsString::UpperAllString(Currency2.CurrencyCode()) != "USD") {
			Result = Currency1.ConvertToOtherCurrency(Amount, Currency2);
			cout << "\n\nConvert to :";
			Currency2.Print();
		}
		else {
			Result = Currency1.ConvertToUSD(Amount);
		}
		_PrintResult(Amount, Currency1.CurrencyCode(), Currency2.CurrencyCode(), Result);
	}
};

