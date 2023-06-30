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
	bool _MarkAsDeleted;

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;
	static clsBankClient _ConvertLinetoClientObject(string Line, string Delimiter = "#//#")
	{
		vector<string> vClientData = clsString::split(Line, Delimiter);
		return clsBankClient(vClientData[0], vClientData[1], vClientData[2],
			vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]), enMode::UpdateMode);
	}
	static string _ConvertClientObjecttoLine(clsBankClient Client, string Delimiter = "#//#")
	{
		string stClientRecord = "";
		stClientRecord += Client.FirstName + Delimiter;
		stClientRecord += Client.LastName + Delimiter;
		stClientRecord += Client.Email + Delimiter;
		stClientRecord += Client.Phone + Delimiter;
		stClientRecord += Client.AccountNumber + Delimiter;
		stClientRecord += Client.PinCode + Delimiter;
		stClientRecord += to_string(Client.AccountBalance);

		return stClientRecord;
	}
	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient("", "", "", "", "", "", 0, enMode::EmptyMode);
	}
	static vector<clsBankClient> _LoadClientsDataFromFile() {
		vector<clsBankClient> vClients;
		fstream File;

		File.open("Clients.txt", ios::in);
		if (File.is_open()) {
			string Line;
			while (getline(File, Line)) {
				vClients.push_back(_ConvertLinetoClientObject(Line));
			}
			File.close();
		}
		return vClients;
	}
	static void _SaveClientsDataToFile(vector<clsBankClient> vClients) {
		fstream File;
		File.open("Clients.txt", ios::out);

		if (File.is_open()) {
			for (clsBankClient Client : vClients) {
				if (!Client.MarkAsDeleted)
					File << _ConvertClientObjecttoLine(Client) << endl;
			}
			File.close();
		}
	}
	void _Update() {
		vector<clsBankClient>vClients = _LoadClientsDataFromFile();
		for (clsBankClient& Client : vClients) {
			if (Client.AccountNumber == GetAccountNumber()) {
				Client = *this;
				break;
			}
		}
		_SaveClientsDataToFile(vClients);
	}
	void _AddNewLineToFile(string NewLine) {
		fstream File;
		File.open("Clients.txt", ios::out | ios::app);
		if (File.is_open()) {
			File << NewLine << endl;
		}
		File.close();
	}
	void _AddNew() {
		_AddNewLineToFile(_ConvertClientObjecttoLine(*this));
	}
public:
	clsBankClient(string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance, enMode Mode)
		:clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
		_MarkAsDeleted = false;
	};

	string GetAccountNumber() {
		return _AccountNumber;
	};
	_declspec(property(put = SetAccountNumber, get = GetAccountNumber))string AccountNumber;

	void SetAccountBalance(float AccountBalance) {
		_AccountBalance = AccountBalance;
	};
	float GetAccountBalance() {
		return _AccountBalance;
	};
	_declspec(property(put = SetAccountBalance, get = GetAccountBalance))float AccountBalance;

	void SetPinCode(string PinCode) {
		_PinCode = PinCode;
	};
	string GetPinCode() {
		return _PinCode;
	};
	_declspec(property(put = SetPinCode, get = GetPinCode))string PinCode;

	void SetMarkAsDeleted(bool MarkAsDeleted) {
		_MarkAsDeleted = MarkAsDeleted;
	};
	bool GetMarkAsDeleted() {
		return _MarkAsDeleted;
	};
	_declspec(property(put = SetMarkAsDeleted, get = GetMarkAsDeleted))bool MarkAsDeleted;

	bool IsEmpty() {
		return(_Mode == enMode::EmptyMode);
	};
	static clsBankClient Find(string AccountNumber) {
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
	static clsBankClient Find(string AccountNumber, string PinCode) {
		clsBankClient Client = Find(AccountNumber);
		return  Client.PinCode == PinCode ? Client : _GetEmptyClientObject();
	};
	static bool IsClientExist(string AccountNumber) {
		return (!Find(AccountNumber).IsEmpty());
	};

	static enum enSaveResult { svFailedEmptyClient, svSuccess, svFailedAddExistsClient };
	enSaveResult Save() {
		if (_Mode == enMode::EmptyMode)
			return svFailedEmptyClient;
		if (_Mode == enMode::UpdateMode) {
			_Update();
			return svSuccess;
		}
		if (_Mode == enMode::AddNewMode) {
			_AddNew();
			return svSuccess;
		}
	}

	static clsBankClient GetNewClientObject(string AccountNumber) {
		return clsBankClient("", "", "", "", AccountNumber, "", 0, enMode::AddNewMode);
	}
	bool Delete() {
		vector<clsBankClient>vClients = _LoadClientsDataFromFile();
		for (clsBankClient& Client : vClients) {
			if (Client.AccountNumber == GetAccountNumber()) {
				Client.MarkAsDeleted = true;
				break;
			}
		}
		_SaveClientsDataToFile(vClients);
		*this = _GetEmptyClientObject();
		return true;
	}

	static vector<clsBankClient> GetClientsList() {
		return _LoadClientsDataFromFile();
	}
	static double GetTotalBalances() {
		vector<clsBankClient> VClients = GetClientsList();
		double Total = 0;
		for (clsBankClient Client : VClients)
		{
			Total += Client.AccountBalance;
		}
		return Total;
	}
};