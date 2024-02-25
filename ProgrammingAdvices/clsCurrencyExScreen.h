#pragma once
#include <iostream>
#include"clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"
#include <iomanip>


class clsCurrencyExScreen : protected clsScreen
{
private:
	enum enCurrencyExMenueOptions {
		eCurrencies = 1, eFindCurrency = 2,
		eUpdateRate = 3, eCurrencyCalculator = 4, eMainMenu = 5
	};

	static short _ReadCurrencyExMenuOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
		return Choice;
	}


	static void _ShowCurrenciesScreen()
	{
		//cout << "\n Currencies Screen will be here.\n";
		clsCurrenciesListScreen::ShowCurrenciesListScreen();
	}

	static void _ShowFindCurrencyScreen()
	{
		//cout << "\n FindCurrency Screen will be here.\n";
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateRateScreen()
	{
		//cout << "\n UpdateRate Screen will be here.\n";
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}
	static void _ShowCurrencyCalculatorScreen()
	{
		//cout << "\n CurrencyCalculator Screen will be here.\n";
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void _GoBackToTransactionsMenu()
	{
		cout << "\n\nPress any key to go back to Transactions Menue...";
		system("pause>0");
		ShowCurrencyExchangeMenu();

	}

	static void _PerformCurrencyExMenuOption(enCurrencyExMenueOptions TransactionsMenuOption)
	{
		switch (TransactionsMenuOption)
		{
		case enCurrencyExMenueOptions::eCurrencies:
		{
			system("cls");
			_ShowCurrenciesScreen();
			_GoBackToTransactionsMenu();
			break;
		}

		case enCurrencyExMenueOptions::eFindCurrency:
		{
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToTransactionsMenu();
			break;
		}

		case enCurrencyExMenueOptions::eUpdateRate:
		{
			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToTransactionsMenu();
			break;
		}
		case enCurrencyExMenueOptions::eCurrencyCalculator:
		{
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToTransactionsMenu();
			break;
		}

		case enCurrencyExMenueOptions::eMainMenu:
		{
			//do nothing here the main screen will handle it :-) ;
		}
		}


	}



public:


	static void ShowCurrencyExchangeMenu()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pCurrenvyEx)) {
			return;
		}
		system("cls");

		_DrawScreenHeader("\tCurrency Exchange Main Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\tCurrency Exchange Menu\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menu\n";

		cout << setw(37) << left << "" << "===========================================\n";

		_PerformCurrencyExMenuOption((enCurrencyExMenueOptions)_ReadCurrencyExMenuOption());
	}

};




