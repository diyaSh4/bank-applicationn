#pragma once
#include <iostream>
#include <iomanip>
#include "clsBanckClient.h";
#include "clsScreen.h";
#include "clsInputValidate.h";
using namespace std;

class clsDeleteClientSecreen : protected clsScreen
{
private:
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
	static void ShowDeleteClientSecreen() {
		_DrawScreenHeader("\tDelete client secreen");

		string AccountNumber = "";
		
		    cout << "\nPlease Enter client Account Number: ";
		    AccountNumber = clsInputValidate::ReadString();
		
		    while (!clsBankClient::IsClientExist(AccountNumber))
		    {
		        cout << "\nAccount number is not found, choose another one: ";
		        AccountNumber = clsInputValidate::ReadString();
		    }
		
		    clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		    _PrintClient(Client1);
		
		    cout << "\nAre you sure you want to delete this client? y/n";
		    char Answer = 'n';
		    cin >> Answer;
		
		    if (Answer == 'y' || Answer == 'Y') {
		        if (Client1.Delete()) {
		            cout << "\nClient deleted successflly :-)";
		            _PrintClient(Client1);
		        }
		        else {
		            cout << "\nError, Client was not deleted..\n";
		        }
		    }
	}
};

