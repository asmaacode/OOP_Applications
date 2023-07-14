#pragma once
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "clsUtils.h"
#include "clsDate.h"
#include "Global.h"

class clsLoginScreen : protected clsScreen
{
private:
	static void _Login() {
		string UserName = "", Password = "";
		bool LoginFaild = false;
		
		do {
			if (LoginTrail == 3)
			{
				cout << "Your are Locked after 3 faild trails \n \n";
				return;
			}
			if (LoginFaild) {
				cout << "Invalid Username or Password !" << endl;
				cout << "\nYou have " << (LoginTrail)<< " Trial(s) to login.\n\n";
			}
			cout << "Enter Username ? ";
			cin >> UserName;
			cout << "Enter Password ? ";
			cin >> Password;
			CurrentUser = CurrentUser.Find(UserName, Password);
			LoginFaild = CurrentUser.IsEmpty();
			LoginTrail++;
		} while (LoginFaild);
		
		if (!LoginFaild){
			CurrentUser.RegisterLogIn();
			clsMainScreen::ShowMainMenu();
			LoginTrail = 0;
		}
			
	}
public:
	static void ShowLoginScreen() {
		system("cls");
		clsScreen::_DrawScreenHeader("Login Screen", "");
		_Login();
	}
};

