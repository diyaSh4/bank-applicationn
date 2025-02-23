#pragma once
#include <iostream>
#include <iomanip>
#include "clsBanckClient.h";
#include "clsScreen.h";
#include "clsInputValidate.h";

using namespace std;

class clsAddNewClientsScreen : protected clsScreen
{
private:

    static void _ReadClientInfo(clsBankClient& Client) {

        cout << "\nEnter FirstName: ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        Client.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        Client.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\nEnter PinCode: ";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\nEnter Account Balance: ";
        Client.AccountBalance = clsInputValidate::ReadFloatNumber();

    }

    static void _PrintClient(clsBankClient Client) {

        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

public:
	static void ShowAddNewClientScreen() {
		_DrawScreenHeader("\t Add new client screen..");

        string AccountNumber = "";
        cout << "\nPlease enter account number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (clsBankClient::IsClientExist(AccountNumber)) {
            cout << "\nAccount Number is already used, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        
        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

        _ReadClientInfo(NewClient);

        clsBankClient::enSaveResults SaveResult;
        SaveResult = NewClient.Save();

        switch (SaveResult) {
        case clsBankClient::enSaveResults::svSucceeded: {
            cout << "\nAccount Addeded Successfully :-)";
            _PrintClient(NewClient);
            break;
        }
        case clsBankClient::enSaveResults::svFaildEmptyObject: {
            cout << "\nError account was not saved because it's empty";
            break;
        }
        case clsBankClient::enSaveResults::svFaildAccountNumberExists: {
            cout << "\nAccount news";
            break;
        }
        }
	}
};

