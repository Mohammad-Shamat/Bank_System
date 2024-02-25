#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>

using namespace std;

class clsTransferLogScreen : protected clsScreen
{

private:

	static void _PrintClientRecordBalanceLine(clsBankClient::stTransferLog transferLog)
	{
		cout << setw(8) << left << "" << "| " << setw(25) << left << transferLog.dateTime;
		cout << "| " << setw(10) << left << transferLog.accSourceClient;
		cout << "| " << setw(10) << left << transferLog.accDestinationClient;
		cout << "| " << setw(10) << left << transferLog.amount;
		cout << "| " << setw(10) << left << transferLog.accBalanceSourceClient;
		cout << "| " << setw(10) << left << transferLog.accBalanceDestinationClient;
		cout << "| " << setw(10) << left << transferLog.userName;
	}

public:


	static void ShowTransferLogScreen()
	{
		vector <clsBankClient::stTransferLog> vTransferLog = clsBankClient::GetTransferLogList();
		string Title = "\tTransfer Log List Screen";
		string SubTitle = "\t    (" + to_string(vTransferLog.size()) + ") Record(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(25) << "Date/Time";

		cout << "| " << left << setw(10) << "s.Acct";
		cout << "| " << left << setw(10) << "d.Acct";
		cout << "| " << left << setw(10) << "Amount";
		cout << "| " << left << setw(10) << "s.Balance";
		cout << "| " << left << setw(10) << "d.Balance";
		cout << "| " << left << setw(10) << "User";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;

		for (clsBankClient::stTransferLog& tr : vTransferLog) {
			_PrintClientRecordBalanceLine(tr);
			cout << endl;
		}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;
	}


};

