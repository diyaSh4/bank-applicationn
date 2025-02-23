#pragma once
#include <iostream>
#include "clsDate.h";
#include "clsUser.h";
#include "global.h";

using namespace std;

class clsScreen {
protected:
	static void _DrawScreenHeader(string Title, string SubTitle = "") {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        //cout << "\n\t\t\t\t\t______________________________________\n\n";
        cout << "\n\t\t\t\t\t______________________________________\n";
        cout << "\n\t\t\t\t\tUser: " << CurrentUser.UserName << "\n";
        cout << "\t\t\t\t\tDate: " << clsDate::DateToString(clsDate())
            << "\n\n";
	}
};

