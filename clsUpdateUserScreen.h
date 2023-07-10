#pragma once
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"

class clsUpdateUserScreen : protected clsScreen
{
public:
	static void UpdateUser() {
		clsScreen::_DrawScreenHeader("Update User", "");
		string UserName = clsInputValidate::readText(" \n");
		while (UserName == "") {
			UserName = clsInputValidate::readText("\nPlease enter the username you want to update:");
		}
		while (!clsUser::IsUserExist(UserName)) {
			cout << "Sorry! The username does not exist ! \n";
			UserName = clsInputValidate::readText("\nPlease enter the username you want to update:");
		}
		clsUser CurrentUser = clsUser::Find(UserName);
		cout << "The founded user  :\n";
		CurrentUser.Print();
		clsInputValidate::EnterUserData(CurrentUser);
		switch (CurrentUser.Save())
		{
		case clsUser::svSuccess:
			cout << "User Updated Successfully !";
			CurrentUser.Print();
			break;
		case clsUser::svFailedEmptyUser:
			cout << "\nError user was not saved because it's empty";
			break;
		}
	}
};

