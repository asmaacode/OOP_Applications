#pragma once
#include"clsInputValidate.h"
#include"clsScreen.h"

class clsFindUserScreen :protected clsScreen
{
public:
	static void FindUser() {
		clsScreen::_DrawScreenHeader("Find User", "");
		string UserName = clsInputValidate::readText(" \n");
		while (UserName == "") {
			UserName = clsInputValidate::readText("\nPlease enter the username you want to find:");
		}
		if (!clsUser::IsUserExist(UserName)) {
			cout << "Sorry! The username does not exist ! \n";
			return;
		}
		clsUser CurrentUser = clsUser::Find(UserName);
		cout << "The founded user  :\n";
		CurrentUser.Print();
	}
};