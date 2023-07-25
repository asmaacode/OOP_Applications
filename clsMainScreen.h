#pragma once
#include"Global.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsClientsListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include"clsManageUsersScreen.h"
#include"clsLoginLogScreen.h"
#include"clsCurrencyMenuScreen.h"


class clsMainScreen : protected clsScreen
{
private:
	enum enMainMenuOptions {
		enListClients = 1, enAddNewClient = 2, enDeleteClient = 3,
		enUpdateClient = 4, enFindClient = 5, enShowTransactionsMenu = 6,
		enManageUsers = 7, enShowLoginLogList = 8, enCurrencyExchange = 9, enExit = 10
	};
	static enMainMenuOptions _ReadMainMenuOption() {
		string msg = clsDrawer::generateTabs(35) + "Choose what you want to do? [1-10]" + "  ";
		return (enMainMenuOptions)clsInputValidate::readNumberBetween(1, 10, msg);
	}
	static  void _GoBackToMainMenu()
	{
		cout << "\nPress any key to go back to Main Menu...\n";
		system("pause>0");
		ShowMainMenu();
	}
	static void _ShowAllClientsScreen()
	{
		if (!CheckAccessRights(clsUser::enRights::enShowClients))
		{
			return;// this will exit the function and it will not continue
		}
		clsClientsListScreen::ShowClientsList();
	}
	static void _ShowAddNewClientsScreen()
	{
		if (!CheckAccessRights(clsUser::enRights::enAddNewClient))
		{
			return;// this will exit the function and it will not continue
		}
		clsAddNewClientScreen::AddNewClient();
	}
	static void _ShowDeleteClientScreen()
	{
		if (!CheckAccessRights(clsUser::enRights::enDeleteClient))
		{
			return;// this will exit the function and it will not continue
		}
		clsDeleteClientScreen::DeleteClient();
	}
	static void _ShowUpdateClientScreen()
	{
		if (!CheckAccessRights(clsUser::enRights::enUpdateClient))
		{
			return;// this will exit the function and it will not continue
		}
		clsUpdateClientScreen::UpdateClient();
	}
	static void _ShowFindClientScreen()
	{
		if (!CheckAccessRights(clsUser::enRights::enFindClient))
		{
			return;// this will exit the function and it will not continue
		}
		clsFindClientScreen::FindClient();
	}
	static void _ShowTransactionsMenu()
	{
		if (!CheckAccessRights(clsUser::enRights::enTransactions))
		{
			return;// this will exit the function and it will not continue
		}
		clsTransactionsScreen::ShowTransactionsMenu();
	}
	static void _ShowManageUsersMenu()
	{
		if (!CheckAccessRights(clsUser::enRights::enManageUsers))
		{
			return;// this will exit the function and it will not continue
		}
		clsManageUsersScreen::ShowManageUsersMenu();
	}
	static void _ShowLoginLogListScreen()
	{
		if (!CheckAccessRights(clsUser::enRights::enShowLoginLog))
		{
			return;// this will exit the function and it will not continue
		}
		clsLoginLogScreen::ShowLoginLogList();
	}
	static void _ShowCurrencyExchangeMenu()
	{
		if (!CheckAccessRights(clsUser::enRights::enCurrencyExchange))
		{
			return;// this will exit the function and it will not continue
		}
		clsCurrencyMenuScreen::ShowCurrencyMenu();
	}
	static void _ShowEndScreen()
	{
		CurrentUser = CurrentUser.Find("", "");
	}
	static void _PerfromMainMenuOption(enMainMenuOptions MainMenuOption)
	{
		switch (MainMenuOption)
		{
		case enMainMenuOptions::enListClients:
		{
			system("cls");
			_ShowAllClientsScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::enAddNewClient:
			system("cls");
			_ShowAddNewClientsScreen();
			_GoBackToMainMenu();
			break;

		case enMainMenuOptions::enDeleteClient:
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenu();
			break;

		case enMainMenuOptions::enUpdateClient:
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenu();
			break;

		case enMainMenuOptions::enFindClient:
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenu();
			break;

		case enMainMenuOptions::enShowTransactionsMenu:
			system("cls");
			_ShowTransactionsMenu();
			_GoBackToMainMenu();
			break;

		case enMainMenuOptions::enManageUsers:
			system("cls");
			_ShowManageUsersMenu();
			_GoBackToMainMenu();
			break;

		case enMainMenuOptions::enShowLoginLogList:
			system("cls");
			_ShowLoginLogListScreen();
			_GoBackToMainMenu();
			break;

		case enMainMenuOptions::enCurrencyExchange:
			system("cls");
			_ShowCurrencyExchangeMenu();
			_GoBackToMainMenu();
			break;

		case enMainMenuOptions::enExit:
			system("cls");
			_ShowEndScreen();
			break;
		}
	}

public:
	static void ShowMainMenu() {
		system("cls");
		_DrawScreenHeader("Main Screen", "");
		cout << "\n";
		cout << left << clsDrawer::generateTabs(35) << clsDrawer::generateLine(40, '=') << "\n";
		cout << left << clsDrawer::generateTabs(50) << "Main Menu\n";
		cout << left << clsDrawer::generateTabs(35) << clsDrawer::generateLine(40, '=') << "\n";
		cout << left << clsDrawer::generateTabs(40) << "[1] Show Client List.\n";
		cout << left << clsDrawer::generateTabs(40) << "[2] Add New Client.\n";
		cout << left << clsDrawer::generateTabs(40) << "[3] Delete Client.\n";
		cout << left << clsDrawer::generateTabs(40) << "[4] Update Client Info.\n";
		cout << left << clsDrawer::generateTabs(40) << "[5] Find Client.\n";
		cout << left << clsDrawer::generateTabs(40) << "[6] Transactions.\n";
		cout << left << clsDrawer::generateTabs(40) << "[7] Manage Users.\n";
		cout << left << clsDrawer::generateTabs(40) << "[8] Login Log List.\n";
		cout << left << clsDrawer::generateTabs(40) << "[9] Currency Exchange.\n";
		cout << left << clsDrawer::generateTabs(40) << "[10] Logout.\n";
		cout << left << clsDrawer::generateTabs(35) << clsDrawer::generateLine(40, '=') << "\n";

		_PerfromMainMenuOption(_ReadMainMenuOption());
	}
};

