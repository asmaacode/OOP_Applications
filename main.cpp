#include <iostream>
#include"clsLoginScreen.h"
#include"clsUtils.h"
using namespace std;
int   main() {
	clsUtils::sRand();
	while (LoginTrail == 0)
		clsLoginScreen::ShowLoginScreen();


	system("pause>0");
	return 0;
};		