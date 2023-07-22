#pragma once
#include<string>
#include<vector>
#include<fstream>
#include"clsString.h"
#include"clsUtils.h"
using namespace std;
class clsCurrency
{
private:
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;
	enum enMode { enEmpty = 0, enUpdate = 1 };
	enMode _Mode;
	static clsCurrency _ConvertLinetoCurrencyObject(string Line, string Delimiter = "#//#")
	{
		vector<string> vCurrencyData = clsString::Split(Line, Delimiter);
		return clsCurrency(enMode::enUpdate, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2], stof(vCurrencyData[3]));
	}
	static string _ConvertCurrencyObjecttoLine(clsCurrency Currency, string Delimiter = "#//#")
	{
		string stRecord = "";
		stRecord += Currency._Country + Delimiter;
		stRecord += Currency._CurrencyCode + Delimiter;
		stRecord += Currency._CurrencyName + Delimiter;
		stRecord += to_string(Currency._Rate);

		return stRecord;
	}
	static vector<clsCurrency> _LoadCurrencyDataFromFile() {
		vector<clsCurrency> vCurrencies;
		fstream File;

		File.open("Currencies.txt", ios::in);
		if (File.is_open()) {
			string Line;
			while (getline(File, Line)) {
				vCurrencies.push_back(_ConvertLinetoCurrencyObject(Line));
			}
			File.close();
		}
		return vCurrencies;
	}
	static void _SaveCurrencyDataToFile(vector<clsCurrency> vCurrencies) {
		fstream File;
		File.open("Currencies.txt", ios::out);

		if (File.is_open()) {
			for (clsCurrency Currency : vCurrencies) {
				File << _ConvertCurrencyObjecttoLine(Currency) << endl;
			}
			File.close();
		}
	}
	void _Update() {
		vector<clsCurrency>vCurrencies = _LoadCurrencyDataFromFile();
		for (clsCurrency& Currency : vCurrencies) {
			if (Currency._CurrencyCode == _CurrencyCode) {
				Currency = *this;
				break;
			}
		}
		_SaveCurrencyDataToFile(vCurrencies);
	}
	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::enEmpty, "", "", "", 0);
	}

public:
	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate) {
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
		_Mode = Mode;
	}
	bool IsEmpty() {
		return (_Mode == enMode::enEmpty);
	}
	string Country() {
		return _Country;
	}
	string CurrencyCode() {
		return _CurrencyCode;
	}
	string CurrencyName() {
		return _CurrencyName;
	}
	float Rate() {
		return _Rate;
	}
	void UpdateRate(float NewRate) {
		_Rate = NewRate;
		_Update();
	}
	static vector<clsCurrency> GetCurrenciesList() {
		return _LoadCurrencyDataFromFile();
	}
	static clsCurrency FindByCode(string CurrencyCode) {
		vector <clsCurrency> vCurrencies;
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
				if (clsString::UpperAllString(Currency.CurrencyCode()) == clsString::UpperAllString(CurrencyCode))
				{
					MyFile.close();
					return Currency;
				}
			}
			MyFile.close();
		}
		return _GetEmptyCurrencyObject();
	}
	static clsCurrency FindByCountry(string Country) {
		vector <clsCurrency> vCurrencies;
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
				if (clsString::UpperAllString(Currency.Country()) == clsString::UpperAllString(Country))
				{
					MyFile.close();
					return Currency;
				}
			}
			MyFile.close();
		}
		return _GetEmptyCurrencyObject();
	}
	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		return (!Currency.IsEmpty());
	}

};