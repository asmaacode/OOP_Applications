#pragma once
#include <string>
using namespace std;
class clsDrawer
{
public:
	static string generateLine(short length = 0, char symbol = '_') {
		string line = "";
		while (length != 0) {
			line += symbol;
			length--;
		}
		return line;
	};
	static string generateTabs(short length = 0) {
		string tabs = "";
		while (length != 0) {
			tabs += " ";
			length--;
		}
		return tabs;
	};
};

