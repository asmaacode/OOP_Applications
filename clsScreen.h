#pragma once
#include <iostream>
#include"clsDrawer.h"
using namespace std;

class clsScreen
{
protected:
	 static void _DrawScreenHeader(string Title,string SubTitle) {
		cout << clsDrawer::generateTabs(30) << clsDrawer::generateLine(50,'.') << endl;
		cout << clsDrawer::generateTabs(50) <<Title<<"\n";
		if (SubTitle != "")
		{
			cout << clsDrawer::generateTabs(51) << SubTitle << "\n";
		}
		cout << clsDrawer::generateTabs(30) <<clsDrawer::generateLine(50,'.') << endl;
	}
};

