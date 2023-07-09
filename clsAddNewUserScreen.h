#pragma once
#include"clsUser.h"
#include"clsInputValidate.h"
#include"clsDrawer.h"
#include"clsScreen.h"
#include<iomanip>
using namespace std;
class clsAddNewUserScreen : protected clsScreen
{
public:
	static void AddNewUser() {
		clsScreen::_DrawScreenHeader("Add New User", "");
		string UserName = clsInputValidate::readText(" \n");
		while (UserName == "") {
			UserName = clsInputValidate::readText("\nPlease enter the new username :");
		}
		while (clsUser::IsUserExist(UserName)) {
			cout << "Sorry! The Username already exists ! \n";
			UserName = clsInputValidate::readText("Please enter the new username :");
		}
		clsUser CurrentUser = clsUser::GetNewUserObject(UserName);
		clsInputValidate::EnterUserData(CurrentUser);
		switch (CurrentUser.Save())
		{
		case clsUser::svSuccess:
			cout << "The new user added successfully !\n";
			CurrentUser.Print();
			break;
		case clsUser::svFailedEmptyUser:
			cout << "\nError user was not saved because it's empty.\n";
			break;
		case clsUser::svFailedAddExistsUser:
			cout << "\nError user already exists.\n";
			break;
		}
	}
};

