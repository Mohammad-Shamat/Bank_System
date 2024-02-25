#include <iostream>
#include"clsLoginScreen.h"

int main()

{
	
	//clsMainScreen::ShowMainMenu();
	while (true) {
		if (!clsLoginScreen::ShowLoginScreen()) 
		{
			
			break;
		};
	}

	system("pause>0");
	return 0;
}