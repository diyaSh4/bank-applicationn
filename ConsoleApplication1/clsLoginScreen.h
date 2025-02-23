#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsUser.h";
#include "clsMainScreen.h";
#include "global.h";

using namespace std;

class clsLoginScreen : protected clsScreen
{

private:
	static bool _Login() {
		bool LoginFaild = false;
		short FaildLoginCount = 0;

		string Username, Password;
		do {
		if (LoginFaild) {
			FaildLoginCount++;
			cout << "\nInvalid username/password\n\n";
			cout << "You have " << (3 - FaildLoginCount) << " trials to login.\n";
		}

		if (FaildLoginCount == 3) {
			cout << "You are locked after 3 faild trials.\n";
			return false;
		}
			cout << "Enter Username\n";
			cin >> Username;
			cout << "Enter Password\n";
			cin >> Password;

			CurrentUser = clsUser::Find(Username, Password);
			LoginFaild = CurrentUser.IsEmpty();
		} while (LoginFaild);

		CurrentUser.RegisterLogin();
		clsMainScreen::ShowMainMenu();
		return true;
	}

public:
	static bool ShowLoginScreen() {
		system("cls");
		_DrawScreenHeader("\t      Login screen");
		return _Login();
	}
};

