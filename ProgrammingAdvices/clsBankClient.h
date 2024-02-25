#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>

using namespace std;

const string _dbClients = "Clients.txt";
const string _dbTransferLog = "TransferLog.txt";

class clsBankClient : public clsPerson
{
private:

	enum enMode {
		EmptyMode = 0,
		UpdateMode = 1,
		AddNewMode = 2,

	};

	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _markedForDelete = false;

	static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
	{
		vector<string> vClientData;
		vClientData = clsString::Split(Line, Seperator);

		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
			vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));

	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
	{
		string stClientRecord = "";
		stClientRecord += Client.FirstName + Seperator;
		stClientRecord += Client.LastName + Seperator;
		stClientRecord += Client.Email + Seperator;
		stClientRecord += Client.Phone + Seperator;
		stClientRecord += Client.AccountNumber() + Seperator;
		stClientRecord += Client.PinCode + Seperator;
		stClientRecord += to_string(Client.AccountBalance);

		return stClientRecord;
	}

	static  vector <clsBankClient> _LoadClientsDataFromFile()
	{
		vector <clsBankClient> vClients;
		fstream MyFile;
		MyFile.open(_dbClients, ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{

				clsBankClient Client = _ConvertLinetoClientObject(Line);

				vClients.push_back(Client);
			}
			MyFile.close();
		}
		return vClients;
	}

	static void _SaveCleintsDataToFile(vector <clsBankClient> vClients)
	{

		fstream MyFile;
		MyFile.open(_dbClients, ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsBankClient& tempClient : vClients)
			{
				if (tempClient.MarkedForDeleted() == false) {
					DataLine = _ConverClientObjectToLine(tempClient);
					MyFile << DataLine << endl;
				}
			}
			MyFile.close();

		}

	}


	void _Update()
	{
		vector <clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}

		}

		_SaveCleintsDataToFile(_vClients);

	}



	void _AddDataLineToFile(string dataLine)
	{
		fstream MyFile;
		MyFile.open(_dbClients, ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << dataLine << endl;

			MyFile.close();
		}

	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConverClientObjectToLine(*this));
	}

	string _PrepareTransferLogInRecord(float amount, clsBankClient destinationClient, string username, string Seperator = "#//#")
	{
		string stTransferLogRecord = "";
		stTransferLogRecord += clsDate::GetSystemDateTimeString() + Seperator;
		stTransferLogRecord += AccountNumber() + Seperator;
		stTransferLogRecord += destinationClient.AccountNumber() + Seperator;
		stTransferLogRecord += to_string(amount) + Seperator;
		stTransferLogRecord += to_string(AccountBalance) + Seperator;
		stTransferLogRecord += to_string(destinationClient.AccountBalance) + Seperator;
		stTransferLogRecord += username;


		return stTransferLogRecord;
	}

	void _TransferLog(float amount, clsBankClient destinationClient, string username)
	{

		string stDataLine = _PrepareTransferLogInRecord(amount, destinationClient, username);

		fstream MyFile;
		MyFile.open(_dbTransferLog, ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}

	struct stTransferLog;
	static stTransferLog _ConvertstTransferLogToRecord(string Line, string Seperator = "#//#")
	{
		stTransferLog TransferLogRegisterRecord;

		vector<string> vTransferLog;
		vTransferLog = clsString::Split(Line, Seperator);

		TransferLogRegisterRecord.dateTime = vTransferLog[0];
		TransferLogRegisterRecord.accSourceClient = vTransferLog[1];
		TransferLogRegisterRecord.accDestinationClient = vTransferLog[2];
		TransferLogRegisterRecord.amount = stoi(vTransferLog[3]);
		TransferLogRegisterRecord.accBalanceSourceClient = stoi(vTransferLog[4]);
		TransferLogRegisterRecord.accBalanceDestinationClient = stoi(vTransferLog[5]);
		TransferLogRegisterRecord.userName = vTransferLog[6];

		return TransferLogRegisterRecord;

	}

public:

	clsBankClient(enMode Mode, string FirstName, string LastName,
		string Email, string Phone, string AccountNumber, string PinCode,
		float AccountBalance) :
		clsPerson(FirstName, LastName, Email, Phone) {

		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;

	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	bool MarkedForDeleted() {
		return _markedForDelete;
	}

	string AccountNumber()
	{
		return _AccountNumber;
	}

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	string GetPinCode()
	{
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	void Print() {
		cout << "\nClient Card:";
		cout << "\n______________________________________";
		cout << "\nFirstName      : " << FirstName;
		cout << "\nLastName       : " << LastName;
		cout << "\nFull Name      : " << FullName();
		cout << "\nEmail          : " << Email;
		cout << "\nPhone          : " << Phone;
		cout << "\nAccount Number : " << _AccountNumber;
		cout << "\nPassword       : " << _PinCode;
		cout << "\nBalance        : " << _AccountBalance;
		cout << "\n______________________________________\n";

	}

	struct stTransferLog {

		string dateTime;
		string accSourceClient;
		string accDestinationClient;
		float amount;
		float accBalanceSourceClient;
		float accBalanceDestinationClient;
		string userName;


	};

	static clsBankClient Find(string AccountNumber) {

		fstream MyFile;
		MyFile.open(_dbClients, ios::in);

		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber, string PinCode) {
		fstream MyFile;
		MyFile.open(_dbClients, ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}

			}

			MyFile.close();

		}
		return _GetEmptyClientObject();
	}

	static bool IsClientExist(string AccountNumber) {
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		return (!Client1.IsEmpty());
	}

	enum enSaveResults {
		svFaildEmptyObject = 0,
		svSucceeded = 1,
		svFaildAccountNumberExists = 2
	};

	enSaveResults Save()
	{

		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			if (IsEmpty()) {
				return enSaveResults::svFaildEmptyObject;
			}

		}

		case enMode::UpdateMode:

		{
			_Update();

			return enSaveResults::svSucceeded;

			break;
		}

		case enMode::AddNewMode:
		{

			if (clsBankClient::IsClientExist(_AccountNumber))
			{
				return enSaveResults::svFaildAccountNumberExists;
			}
			else
			{
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}

			break;
		}

		}
	}

	bool Delete() {

		vector <clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();

		for (clsBankClient& c : _vClients)
		{
			if (c.AccountNumber() == AccountNumber())
			{
				c._markedForDelete = true;
				break;
			}

		}

		_SaveCleintsDataToFile(_vClients);
		*this = _GetEmptyClientObject();
		return true;
	}

	static clsBankClient GetAddNewClientObject(string accountNumber) {
		return clsBankClient(enMode::AddNewMode, "", "", "", "", accountNumber, "", 0);
	}

	static vector <clsBankClient> GetClientsList() {
		return _LoadClientsDataFromFile();
	}

	static float GetTotalBalances()
	{
		vector <clsBankClient> vClients = clsBankClient::GetClientsList();

		double TotalBalances = 0;

		for (clsBankClient& Client : vClients)
		{
			TotalBalances += Client.AccountBalance;
		}

		return TotalBalances;

	}

	void Deposit(double Amount)
	{
		AccountBalance += Amount;
		Save();
	}

	bool Withdraw(double Amount)
	{
		if (Amount > AccountBalance)
		{
			return false;
		}
		else
		{
			AccountBalance -= Amount;
			Save();
			return true;
		}

	}

	bool Transfer(float amount, clsBankClient& destinationClient, string userName) {

		if (amount > AccountBalance) {
			return false;
		}
		Withdraw(amount);
		destinationClient.Deposit(amount);
		_TransferLog(amount, destinationClient, userName);
		return true;
	}

	static vector<stTransferLog> GetTransferLogList()
	{
		vector <stTransferLog> vTransferLog;
		fstream file;
		file.open(_dbTransferLog, ios::in);//read mode only

		if (file.is_open()) {
			string line;
			stTransferLog loginRecord;
			while (getline(file, line)) {

				loginRecord = _ConvertstTransferLogToRecord(line);
				vTransferLog.push_back(loginRecord);
			}
			file.close();
		}
		return vTransferLog;
	}



};

