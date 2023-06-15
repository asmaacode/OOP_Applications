#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "clsPerson.h"
#include "clsString.h"
using namespace std;
class clsBankClient : public clsPerson
{
private:
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;

	enum enMode { EmptyMode = 0, UpdateMode = 1 };
	enMode _Mode;
	static clsBankClient _ConvertLinetoClientObject(string ClientData, string Delimiter = "#//# ") {
		vector<string>vClientData = clsString::split(ClientData, Delimiter);
		return clsBankClient(vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]), enMode::UpdateMode);
	};
	static  vector <clsBankClient> _LoadClientsDataFromFile(string FileName)
	{
		vector <clsBankClient> vClients;
		fstream MyFile;
		MyFile.open(FileName, ios::in);//read Mode
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				vClients.push_back(Client);
			}
			MyFile.close();
		}
		return vClients;
	}
	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient("", "", "", "", "", "", 0, enMode::EmptyMode);
	}

public:
	clsBankClient(string FirstName, string LastName, string Email, string Phone, string AccountNumber, 
		string PinCode, float AccountBalance, enMode Mode)
		:clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	};
	void SetAccountNumber(string AccountNumber) {
		AccountNumber = _AccountNumber;
	};
	string GetAccountNumber() {
		return _AccountNumber;
	};
	_declspec(property(put = SetAccountNumber, get = GetAccountNumber))string AccountNumber;
	void SetAccountBalance(string AccountBalance) {
		AccountBalance = _AccountBalance;
	};
	float GetAccountBalance() {
		return _AccountBalance;
	};
	_declspec(property(put = SetAccountBalance, get = GetAccountBalance))float AccountBalance;
	void SetPinCode(string PinCode) {
		PinCode = _PinCode;
	};
	string GetPinCode() {
		return _PinCode;
	};
	_declspec(property(put = SetPinCode, get = GetPinCode))float PinCode;
	bool IsEmpty() {
		return(_Mode == enMode::EmptyMode);
	};
	clsBankClient Find(string AccountNumber) {
		vector <clsBankClient> vClients;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mode
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				if (Client.AccountNumber == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	};
	clsBankClient Find(string AccountNumber, string PinCode) {
		clsBankClient Client = Find(AccountNumber);
		return  Client.PinCode == PinCode ? Client : _GetEmptyClientObject();
	};

};
