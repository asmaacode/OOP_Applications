#pragma once
#include"clsScreen.h"
#include"clsInputValidate.h"
class clsDeleteUserScreen : protected clsScreen
{
public:
	static void DeleteUser() {
		clsScreen::_DrawScreenHeader("Delete User", "");

		string UserName = clsInputValidate::readText(" \n");
		while (UserName == "") {
			UserName = clsInputValidate::readText("\nPlease enter the username you want to delete:");
		}
		while (!clsUser::IsUserExist(UserName)) {
			cout << "Sorry! The username does not exist ! \n";
			UserName = clsInputValidate::readText("\nPlease enter the username you want to delete:");
		}

		clsUser CurrentUser = clsUser::Find(UserName);
		CurrentUser.Print();
		if (clsInputValidate::doYouQuestion("Do you want to delete this user ?"))
			if (CurrentUser.Delete()) {
				cout << "The user deleted successfully \n";
				//CurrentUser.Print();
			}
			else {
				cout << "The user was not deleted \n";
			}
	}
};