#include<iostream> 
#include"clsLoginScreen.h"
using namespace std;

int   main() {
	while (LoginTrail == 0)
		clsLoginScreen::ShowLoginScreen();

	system("pause>0");
	return 0;
};