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
	static float _ConvertToUSD(float Amount, float Rate) {
		return (Amount / Rate);
	}
	static float _ConvertFromUSD(float Amount, float Rate) {
		return (Amount * Rate);
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
		cout << "Convert From:\n";
		Currency1.Print();	

		float ResultAmount = _ConvertToUSD(Amount, Currency1.Rate());
		_PrintResult(Amount, Currency1.CurrencyCode(), "USD", ResultAmount);

		if (clsString::UpperAllString(Currency2.CurrencyCode()) != "USD") {
			cout << "Convert From USD to :\n";
			Currency2.Print();
			ResultAmount = _ConvertFromUSD(ResultAmount, Currency2.Rate());
			_PrintResult(Amount, Currency1.CurrencyCode(), Currency2.CurrencyCode(), ResultAmount);
		}

	}
};

