#pragma once
#include <iostream>
#include "clsUser.h"
#include "Global.h"

using namespace std;

class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        _DateScreen();
    }

    static void _DateScreen() {
      
        cout << "\t\t\t\t\t  " << "User : " << CurrentUser.GetUserName()<<endl;
        cout << "\t\t\t\t\t  " << "Date : ";
        currentDate.PrintDate();
    }

    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {

        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t\t_______________________________________________________________";
            cout << "\n\n\t\t\t\t\t    Access Denied!To Take Access Please Contact your Admin.";
            cout << "\n\t\t\t\t\t_______________________________________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }

    }

};

