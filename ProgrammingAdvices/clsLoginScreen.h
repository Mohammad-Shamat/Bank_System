#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"

class clsLoginScreen :protected clsScreen
{

private:

	static  bool _Login()
	{
		bool LoginFaild = false;
		short numberOfTrials = 0;
		string Username, Password;
		do
		{

			if (LoginFaild)
			{
				numberOfTrials++;
				cout << "\nInvlaid Username/Password!\n\n";
				cout << "\nYou have " << 3 - numberOfTrials << " Trials To login\n\n";

			}
			if (numberOfTrials == 3) {
				cout << "\nYour are locked after 3 faild trails \n\n";
				return false;
			}
			cout << "Enter Username? ";
			cin >> Username;

			cout << "Enter Password? ";
			cin >> Password;

			CurrentUser = clsUser::Find(Username, Password);

			LoginFaild = CurrentUser.IsEmpty();

		} while (LoginFaild);

		CurrentUser.RegisterLogIn();
		clsMainScreen::ShowMainMenu();
		return true;
	}

public:


	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Login Screen");
		return _Login();

	}

};



