#pragma once
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen : protected clsScreen
{
private:
	static void _Login() {
		string UserName = "", Password = "";
		bool LoginFaild = false;
		do {
			if (LoginFaild)
				cout << "Invalid Username or Password !" << endl;
			cout << "Enter Username ? ";
			cin >> UserName;
			cout << "Enter Password ? ";
			cin >> Password;
			CurrentUser = CurrentUser.Find(UserName, Password);
			LoginFaild = CurrentUser.IsEmpty();
		} while (LoginFaild);

		clsMainScreen::ShowMainMenu();
	}
public:
	static void ShowLoginScreen() {
		system("cls");
		clsScreen::_DrawScreenHeader("Login Screen", "");
		_Login();
	}
};

