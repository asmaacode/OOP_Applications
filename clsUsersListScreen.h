#pragma once
#include"clsUser.h"
#include"clsDrawer.h"
#include"clsScreen.h"
#include<iomanip>

class clsUsersListScreen : protected clsScreen
{
private:
	static void _PrintUsersListHeader() {
		cout << "|" << left << setw(25) << "User Name";
		cout << "|" << left << setw(25) << "Full Name";
		cout << "|" << left << setw(15) << "Phone";
		cout << "|" << left << setw(30) << "Email";
		cout << "|" << left << setw(10) << "Password";
		cout << "|" << left << setw(10) << "Rights" << endl;
		cout << clsDrawer::generateLine(120) << endl;
	}
	static void _PrintUser(clsUser& User) {
		cout << "|" << left << setw(25) << User.UserName;
		cout << "|" << left << setw(25) << User.FullName();
		cout << "|" << left << setw(15) << User.Phone;
		cout << "|" << left << setw(30) << User.Email;
		cout << "|" << left << setw(10) << User.Password;
		cout << "|" << left << setw(10) << to_string(User.Rights) << endl;
	}
public:
	static void ShowUsersList() {
		clsScreen::_DrawScreenHeader("Users List", "");
		_PrintUsersListHeader();
		vector<clsUser>VUsers = clsUser::GetUsersList();
		if (VUsers.size() > 0) {
			for (clsUser User : VUsers)
				_PrintUser(User);
			cout << clsDrawer::generateLine(120) << endl;
			cout << "(" << VUsers.size() << ") Users" << endl;
		}
		else {
			cout << "There is no user in the system yet! \n";
		}
	}
};