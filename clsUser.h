#pragma once
#include"clsPerson.h"
#include"clsString.h"
#include <fstream>
#include <vector>
using namespace std;

class clsUser :public clsPerson
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;
	string _UserName = "";
	string _Password = "";
	int _Rights = -1;
	bool _MarkAsDeleted = false;

	static clsUser _ConvertLinetoUserObject(string Line, string Delimiter = "#//#")
	{
		vector<string> vUserData = clsString::split(Line, Delimiter);
		return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],
			vUserData[3], vUserData[4], vUserData[5], stoi(vUserData[6]));
	}
	static string _ConvertUserObjecttoLine(clsUser User, string Delimiter = "#//#")
	{
		string stUserRecord = "";
		stUserRecord += User.FirstName + Delimiter;
		stUserRecord += User.LastName + Delimiter;
		stUserRecord += User.Email + Delimiter;
		stUserRecord += User.Phone + Delimiter;
		stUserRecord += User.UserName + Delimiter;
		stUserRecord += User.Password + Delimiter;
		stUserRecord += to_string(User.Rights);

		return stUserRecord;
	}
	static clsUser _GetEmptyUser()
	{
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}
	static vector<clsUser> _LoadUsersDataFromFile() {
		vector<clsUser> vUsers;
		fstream File;

		File.open("Users.txt", ios::in);
		if (File.is_open()) {
			string Line;
			while (getline(File, Line)) {
				vUsers.push_back(_ConvertLinetoUserObject(Line));
			}
			File.close();
		}
		return vUsers;
	}
	static void _SaveUsersDataToFile(vector<clsUser> vUsers) {
		fstream File;
		File.open("Users.txt", ios::out);

		if (File.is_open()) {
			for (clsUser User : vUsers) {
				if (!User.MarkAsDeleted)
					File << _ConvertUserObjecttoLine(User) << endl;
			}
			File.close();
		}
	}
	void _Update() {
		vector<clsUser>vUsers = _LoadUsersDataFromFile();
		for (clsUser& User : vUsers) {
			if (User.UserName == UserName) {
				User = *this;
				break;
			}
		}
		_SaveUsersDataToFile(vUsers);
	}
	void _AddNewLineToFile(string NewLine) {
		fstream File;
		File.open("Users.txt", ios::out | ios::app);
		if (File.is_open()) {
			File << NewLine << endl;
		}
		File.close();
	}
	void _AddNew() {
		_AddNewLineToFile(_ConvertUserObjecttoLine(*this));
	}

public:
	clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string UserName, string Password, int Rights)
		:clsPerson(FirstName, LastName, Email, Phone) {
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Rights = Rights;
		_MarkAsDeleted = false;
	}
	bool IsEmpty() {
		return (_Mode == enMode::EmptyMode);
	}

	void SetUserName(string UserName) {
		_UserName = UserName;
	}
	string GetUserName() {
		return _UserName;
	}
	_declspec(property (put = SetUserName, get = GetUserName))string UserName;
	void SetPassword(string Password) {
		_Password = Password;
	}
	string GetPassword() {
		return _Password;
	}
	_declspec(property (put = SetPassword, get = GetPassword))string Password;
	void SetRights(int Rights) {
		_Rights = Rights;
	}
	int GetRights() {
		return _Rights;
	}
	_declspec(property (put = SetRights, get = GetRights))int Rights;
	void SetMarkAsDeleted(bool MarkAsDeleted) {
		_MarkAsDeleted = MarkAsDeleted;
	};
	bool GetMarkAsDeleted() {
		return _MarkAsDeleted;
	};
	_declspec(property(put = SetMarkAsDeleted, get = GetMarkAsDeleted))bool MarkAsDeleted;

	static clsUser Find(string UserName) {
		vector <clsUser> vUsers;
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);//read Mode
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLinetoUserObject(Line);
				if (User.UserName == UserName)
				{
					MyFile.close();
					return User;
				}
			}
			MyFile.close();
		}
		return _GetEmptyUser();
	};
	static clsUser Find(string UserName, string Password) {
		clsUser User = Find(UserName);
		return  User.Password == Password ? User : _GetEmptyUser();
	};
	static bool IsUserExist(string UserName) {
		return (!Find(UserName).IsEmpty());
	};

	static enum enSaveResult { svFailedEmptyUser, svSuccess, svFailedAddExistsUser };
	enSaveResult Save() {
		if (_Mode == enMode::EmptyMode)
			return svFailedEmptyUser;
		if (_Mode == enMode::UpdateMode) {
			_Update();
			return svSuccess;
		}
		if (_Mode == enMode::AddNewMode) {
			_AddNew();
			return svSuccess;
		}
	}

	static clsUser GetNewUserObject(string UserName) {
		return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}
	bool Delete() {
		vector<clsUser>vUsers = _LoadUsersDataFromFile();
		for (clsUser& User : vUsers) {
			if (User.UserName == UserName) {
				User.MarkAsDeleted = true;
				break;
			}
		}
		_SaveUsersDataToFile(vUsers);
		*this = _GetEmptyUser();
		return true;
	}

	static vector<clsUser> GetUsersList() {
		return _LoadUsersDataFromFile();
	}

};

