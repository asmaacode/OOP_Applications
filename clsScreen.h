#pragma once
#include <iostream>
#include"clsDrawer.h"
#include"clsDate.h"
#include"Global.h"
using namespace std;
class clsScreen
{
protected:
	static void _DrawScreenHeader(string Title, string SubTitle) {
		cout << clsDrawer::generateTabs(30) << clsDrawer::generateLine(60, '.') << endl;
		cout << clsDrawer::generateTabs(50) << Title << "\n";
		if (SubTitle != "")
		{
			cout << clsDrawer::generateTabs(51) << SubTitle << "\n";
		}
		cout << clsDrawer::generateTabs(30) << clsDrawer::generateLine(60, '.') << endl;
		cout << clsDrawer::generateTabs(30) << "User : " << CurrentUser.FullName()<<endl;
		cout << clsDrawer::generateTabs(30) << "Date : " << clsDate::dateFormat(clsDate::getSystemDate (),"dd/mm/yyyy")<<endl<<endl;
	}
	static bool CheckAccessRights(clsUser::enRights Right)
	{
		if (CurrentUser.HasRights(Right))
			return true;

		cout << clsDrawer::generateTabs(30) << clsDrawer::generateLine(50, '.') << endl;
		cout << clsDrawer::generateTabs(30) <<"Access Denied! Contact your Admin.\n";
		cout << clsDrawer::generateTabs(30) << clsDrawer::generateLine(50, '.') << endl;

		return false;
	}
};

