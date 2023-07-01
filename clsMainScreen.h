#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;

class clsMainScreen : protected clsScreen
{
private:
    enum enMainMenuOptions{
        enListClients = 1, enAddNewClient = 2, enDeleteClient = 3,
        enUpdateClient = 4, enFindClient = 5, enShowTransactionsMenu = 6,
        enManageUsers = 7, enExit = 8
    };
    static enMainMenuOptions _ReadMainMenuOption() {
        string msg = clsDrawer::generateTabs(35)+"Choose what you want to do? [1-8]" + "  ";
        return (enMainMenuOptions)clsInputValidate::readNumberBetween(1,8,msg);
    }
    static  void _GoBackToMainMenu()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menu...\n";
        system("pause>0");
        ShowMainMenu();
    }
    static void _ShowAllClientsScreen()
    {
        cout << "\nClient List Screen Will be here...\n";


    }
    static void _ShowAddNewClientsScreen()
    {
        cout << "\nAdd New Client Screen Will be here...\n";

    }
    static void _ShowDeleteClientScreen()
    {
        cout << "\nDelete Client Screen Will be here...\n";

    }
    static void _ShowUpdateClientScreen()
    {
        cout << "\nUpdate Client Screen Will be here...\n";

    }
    static void _ShowFindClientScreen()
    {
        cout << "\nFind Client Screen Will be here...\n";

    }
    static void _ShowTransactionsMenu()
    {
        cout << "\nTransactions Menu Will be here...\n";

    }
    static void _ShowManageUsersMenu()
    {
        cout << "\nUsers Menu Will be here...\n";

    }
    static void _ShowEndScreen()
    {
        cout << "\nEnd Screen Will be here...\n";

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
            break;

        case enMainMenuOptions::enManageUsers:
            system("cls");
            _ShowManageUsersMenu();
            break;

        case enMainMenuOptions::enExit:
            system("cls");
            _ShowEndScreen();
            //Login();
            break;
        }
    }

public:
	static void ShowMainMenu() {
		system("cls");
		_DrawScreenHeader("Main Screen","");
        cout << "\n";
        cout << left <<clsDrawer::generateTabs(35) << clsDrawer::generateLine(40,'=') << "\n";
        cout << left << clsDrawer::generateTabs(50) << "Main Menu\n";
       cout << left << clsDrawer::generateTabs(35) << clsDrawer::generateLine(40, '=') << "\n";
        cout << left << clsDrawer::generateTabs(40) << "[1] Show Client List.\n";
        cout << left << clsDrawer::generateTabs(40) << "[2] Add New Client.\n";
        cout << left << clsDrawer::generateTabs(40) << "[3] Delete Client.\n";
        cout << left << clsDrawer::generateTabs(40) << "[4] Update Client Info.\n";
        cout << left << clsDrawer::generateTabs(40) << "[5] Find Client.\n";
        cout << left << clsDrawer::generateTabs(40) << "[6] Transactions.\n";
        cout << left << clsDrawer::generateTabs(40) << "[7] Manage Users.\n";
        cout << left << clsDrawer::generateTabs(40) << "[8] Logout.\n";
        cout << left << clsDrawer::generateTabs(35) << clsDrawer::generateLine(40, '=') << "\n";

        _PerfromMainMenuOption(_ReadMainMenuOption());
	}
};

