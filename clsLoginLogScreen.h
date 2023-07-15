#pragma once
#include"clsDrawer.h"
#include"clsScreen.h"
#include<iomanip>

class clsLoginLogScreen : protected clsScreen
{
private:
	static void _PrintLoginLogListHeader() {
		cout << "|" << left << setw(30) << "Date/Time";
		cout << "|" << left << setw(15) << "User Name";
		cout << "|" << left << setw(15) << "Password";
		cout << "|" << left << setw(20) << "Rights" << endl;
		cout << clsDrawer::generateLine(120) << endl;
	}
	static void _PrintLoginLogList(clsUser::stLoginLogRecord & Record) {
		cout << "|" << left << setw(30) << Record.DateTime;
		cout << "|" << left << setw(25) << Record.UserName;
		cout << "|" << left << setw(15) << Record.Password;
		cout << "|" << left << setw(20) << to_string(Record.Rights) << endl;
	}
public:
	static void ShowLoginLogList() {
		clsScreen::_DrawScreenHeader("Login Log List", "");
		_PrintLoginLogListHeader();
		vector<clsUser::stLoginLogRecord>VLoginLog = clsUser::GetLoginLogList();
		if (VLoginLog.size() > 0) {
			for (clsUser::stLoginLogRecord Record : VLoginLog)
				_PrintLoginLogList(Record);
			cout << clsDrawer::generateLine(120) << endl;
		}
		else {
			cout << "There is no login log record in the system yet! \n";
		}
	}
};



