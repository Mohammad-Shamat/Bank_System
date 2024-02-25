#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionsScreen.h"
#include"clsManageUsersScreen.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyExScreen.h"
#include "Global.h"
#include <iomanip>


using namespace std;

class clsMainScreen :protected clsScreen
{


private:
	enum enMainMenueOptions {
		eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
		eManageUsers = 7, eLoginRe = 8, eCurrencyExchange = 9, eExit = 10,
	};

	static short _ReadMainMenuOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 10, "Enter Number between 1 to 10? ");
		return Choice;
	}

	static  void _GoBackToMainMenu()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menu...\n";

		system("pause>0");
		ShowMainMenu();
	}

	static void _ShowAllClientsScreen()
	{
		clsClientListScreen::ShowClientsList();
		// cout << "\nClient List Screen Will be here soon...\n";


	}

	static void _ShowAddNewClientsScreen()
	{
		// cout << "\nAdd New Client Screen Will be here soon...\n";
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}

	static void _ShowDeleteClientScreen()
	{
		// cout << "\nDelete Client Screen Will be here soon...\n";
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClientScreen()
	{
		//cout << "\nUpdate Client Screen Will be here soon...\n";
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static void _ShowFindClientScreen()
	{
		//cout << "\nFind Client Screen Will be here soon...\n";
		clsFindClientScreen::ShowFindClientScreen();
	}

	static void _ShowTransactionsMenu()
	{
		//cout << "\nTransactions Menu Will be here soon...\n";
		clsTransactionsScreen::ShowTransactionsMenu();
	}

	static void _ShowManageUsersMenu()
	{
		//cout << "\nUsers Menu Will be here soon...\n";
		clsManageUsersScreen::ShowManageUsersMenue();
	}

	static void _ShowLoginRegister()
	{
		//cout << "\nLogin Register screen Will be here soon...\n";
		clsLoginRegisterScreen::ShowLoginRegisterList();
	}

	static void _ShowCurrencyExchange()
	{
		//cout << "\nShow Currency Exchange screen Will be here soon...\n";
		clsCurrencyExScreen::ShowCurrencyExchangeMenu();
	}

	static void _ShowLogoutScreen()
	{
		//cout << "\nEnd Screen Will be here soon...\n";
		CurrentUser = clsUser::Find("", "");

	}

	static void _PerformMainMenuOption(enMainMenueOptions MainMenuOption)
	{
		switch (MainMenuOption)
		{
		case enMainMenueOptions::eListClients:
		{
			system("cls");
			_ShowAllClientsScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenueOptions::eAddNewClient:
			system("cls");
			_ShowAddNewClientsScreen();
			_GoBackToMainMenu();
			break;

		case enMainMenueOptions::eDeleteClient:
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenu();
			break;

		case enMainMenueOptions::eUpdateClient:
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenu();
			break;

		case enMainMenueOptions::eFindClient:
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenu();
			break;

		case enMainMenueOptions::eShowTransactionsMenue:
			system("cls");
			_ShowTransactionsMenu();
			_GoBackToMainMenu();
			break;

		case enMainMenueOptions::eManageUsers:
			system("cls");
			_ShowManageUsersMenu();
			_GoBackToMainMenu();
			break;

		case enMainMenueOptions::eLoginRe:
			system("cls");
			_ShowLoginRegister();
			_GoBackToMainMenu();
			break;

		case enMainMenueOptions::eCurrencyExchange:
			system("cls");
			_ShowCurrencyExchange();
			_GoBackToMainMenu();
			break;

		case enMainMenueOptions::eExit:
			system("cls");
			_ShowLogoutScreen();


			break;
		}

	}



public:


	static void ShowMainMenu()
	{

		system("cls");

		_DrawScreenHeader("\t\tMain Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menu\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] Login Register.\n";
		cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
		cout << setw(37) << left << "" << "\t[10] Logout.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformMainMenuOption((enMainMenueOptions)_ReadMainMenuOption());
	}

};

