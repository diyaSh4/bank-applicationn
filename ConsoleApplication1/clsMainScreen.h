#pragma once
#include "clsInputValidate.h";
#include <iostream>
#include <iomanip>
#include "clsScreen.h";
#include "clsClientListScreen.h";
#include "clsAddNewClientsScreen.h";
#include "clsDeleteClientSecreen.h";
#include "clsUpdateClientSecreen.h";
#include "clsFindClientScreen.h";
#include "clsTransactionsScreen.h";
#include "clsManageUsresScreen.h";
#include "global.h";
#include "clsLoginRegisterScreen.h";
#include "clsCurrencyExchangeMainScreen.h";

using namespace std;

class clsMainScreen : protected clsScreen
{
private:

    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eLoginRegister = 8, CurrencyList = 9, eExit = 10
    };

    static short _ReadMainMenuOptions() {
        cout << setw(37) << left << "" << "Choose what do you want to do ? [1 to 8] ";
        short Choice = clsInputValidate::ReadIntNumberBetween(1, 10, "Enter number between 1 to 10 ");
        return Choice;
    }

    static void _GoBackToMainMenu() {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
        
        system("pause>0");
        ShowMainMenu();
    }

    static void _ShowAllClientsScreen() {
        //cout << "\nClients list screen will be here...\n";
        clsClientListScreen::ShowClientsList();
    }
    static void _ShowAddNewClientsScreen() {
        //cout << "\nAdd new client screen will be here...\n";
        clsAddNewClientsScreen::ShowAddNewClientScreen();
    }
    static void _ShowDeleteClientScreen() {
        //cout << "\nDelete Client Screen Will be here...\n";
        clsDeleteClientSecreen::ShowDeleteClientSecreen();
    }
    static void _ShowUpdateClientScreen() {
        //cout << "\nUpdate Client Screen Will be here...\n";
        clsUpdateClientSecreen::ShowUpdateClientSecreen();
    }
    static void _ShowFindClientScreen() {
        //cout << "\nFind Client Screen Will be here...\n";
        clsFindClientScreen::ShowFindClientSecreen();
    }
    static void _ShowTransactionsMenue() {
       // cout << "\nTransactions Menue Will be here...\n";
        clsTransactionsScreen::ShowTransactionsMenue();
    }
    static void _ShowManageUsersMenue() {
        cout << "\nUsers Menu Will be here...\n";
        clsManageUsresScreen::ShowManageUsersMenue();
    }
    static void _ShowLoginRegisterScreen() {
        //cout << "hello";
        clsLoginRegisterScreen::ShowLoginRegisterScreen();
    }
    static void _ShowCurrencyListScreen() {
         //cout << "\nCurrency List Screen will be here..\n";
        clsCurrencyExchangeMainScreen::ShowCurrenciesMenu();
    }
    static void _ShowEndScreen() {
        //cout << "\nEnd Screen Will be here...\n";
    }
    static void _Logout() {
        CurrentUser = CurrentUser.Find("", "");
    }

    static void _PerformMainMenuOption(enMainMenueOptions MainMenuOption) {

        switch (MainMenuOption) {
        case enMainMenueOptions::eListClients: {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenu();
            break;
        }
        case enMainMenueOptions::eAddNewClient: {
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenu();
            break;
        }
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
            _ShowTransactionsMenue();
            _GoBackToMainMenu();
            break;

        case enMainMenueOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenu();
            break;
        case enMainMenueOptions::eLoginRegister:
            system("cls");
            _ShowLoginRegisterScreen();
            _GoBackToMainMenu();
            break;
        case enMainMenueOptions::CurrencyList:
            system("cls");
            _ShowCurrencyListScreen();
            _GoBackToMainMenu();
            break;
        case enMainMenueOptions::eExit:
            system("cls");
            _Logout();
            break;
        }
    }

public:
	static void ShowMainMenu() {
		system("cls");
		_DrawScreenHeader("\t\tMain Screen");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login Register.\n";
        cout << setw(37) << left << "" << "\t[9] Currency list.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformMainMenuOption((enMainMenueOptions)_ReadMainMenuOptions());

	}
};

