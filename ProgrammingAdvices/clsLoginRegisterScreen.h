#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>

using namespace std;

class clsLoginRegisterScreen: protected clsScreen

{
private :

    static void _PrintUserRecordLine(clsUser::stLoginRegisterRecord login)
    {

        cout << setw(8) << left << "" << "| " << setw(50) << left << login.dateTime;
        
        cout << "| " << setw(20) << left << login.userName;
        cout << "| " << setw(10) << left << login.password;
        cout << "| " << setw(12) << left << login.permission;

    }

public:

    static void ShowLoginRegisterList()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister)) {
            return;
        }
        vector <clsUser::stLoginRegisterRecord> vLogin = clsUser::GetLoginRegisterList();

        string Title = "\t  Login Register List Screen";
        string SubTitle = "\t    (" + to_string(vLogin.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(50) << "Date/Time";
      
        cout << "| " << left << setw(20) << "UserName";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vLogin.size() == 0)
            cout << "\t\t\t\tNo Register Login Available In the System!";
        else

            for (clsUser::stLoginRegisterRecord& User : vLogin)
            {

                _PrintUserRecordLine(User);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }

};
