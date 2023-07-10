#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUsersListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsFindUserScreen.h"
using namespace std;

class clsManageUsersScreen : protected clsScreen
{
private:
	enum enUsersMenuOptions { enUsersList = 1, enAddNewUser = 2, enDeleteUser = 3, enUpdateUser = 4, enFindUser = 5, enMainMenu = 6 };
	static void _ShowUsersListScreen() {
		clsUsersListScreen::ShowUsersList();
	};
	static void _ShowAddNewUserScreen() {
		clsAddNewUserScreen::AddNewUser();
	};
	static void _ShowDeleteUserScreen() {
		clsDeleteUserScreen::DeleteUser();
	};
	static void _ShowUpdateUserScreen() {
		clsUpdateUserScreen::UpdateUser();
	};
	static void _ShowFindUserScreen() {
		clsFindUserScreen::FindUser();
	};
	static enUsersMenuOptions _ReadUsersMenuOption() {
		return (enUsersMenuOptions)clsInputValidate::readNumberBetween(1, 6, "Choose what do you want to do? [1,6]");
	}
	static void _GoBackToUsersMenu() {
		cout << "\nPress any key to go back to Users Menu...\n";
		system("pause>0");
		ShowManageUsersMenu();
	};
	static void _PerfromUsersMenuOption(enUsersMenuOptions UsersMenuOption)
	{
		switch (UsersMenuOption)
		{
		case enUsersMenuOptions::enUsersList:
			system("cls");
			_ShowUsersListScreen();
			_GoBackToUsersMenu();
			break;
		case enUsersMenuOptions::enAddNewUser:
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToUsersMenu();
			break;
		case enUsersMenuOptions::enDeleteUser:
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToUsersMenu();
			break;
		case enUsersMenuOptions::enUpdateUser:
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToUsersMenu();
			break;
		case enUsersMenuOptions::enFindUser:
			system("cls");
			_ShowFindUserScreen();
			_GoBackToUsersMenu();
			break;
		case enUsersMenuOptions::enMainMenu: {

		}
		}
	}
public:
	static void ShowManageUsersMenu() {
		system("cls");
		_DrawScreenHeader("Users Screen", "");
		cout << "\n";
		cout << left << clsDrawer::generateTabs(35) << clsDrawer::generateLine(40, '=') << "\n";
		cout << left << clsDrawer::generateTabs(50) << "Users Menu\n";
		cout << left << clsDrawer::generateTabs(35) << clsDrawer::generateLine(40, '=') << "\n";
		cout << left << clsDrawer::generateTabs(40) << "[1] Users List.\n";
		cout << left << clsDrawer::generateTabs(40) << "[2] Add New User.\n";
		cout << left << clsDrawer::generateTabs(40) << "[3] Delete User.\n";
		cout << left << clsDrawer::generateTabs(40) << "[4] Update User.\n";
		cout << left << clsDrawer::generateTabs(40) << "[5] Find User.\n";
		cout << left << clsDrawer::generateTabs(40) << "[6] Main Menu.\n";
		cout << left << clsDrawer::generateTabs(35) << clsDrawer::generateLine(40, '=') << "\n";

		_PerfromUsersMenuOption(_ReadUsersMenuOption());
	}
};