#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsCurrency.h";
using namespace std;

class clsCurrencyFindScreen : protected clsScreen
{
private:
    static void _PrintCurrency(clsCurrency Currency) {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();
        cout << "\n_____________________________\n";
    }
    static void _ShowResult(clsCurrency Currency) {
        if (!Currency.IsEmpty()) {
            cout << "\nCurrency found :)\n";
            _PrintCurrency(Currency);
        } else {
            cout << "Currency not found :(\n";
        }
    }
public:
	static void ShowCurrrencyFindScreen() {
		_DrawScreenHeader("\t Currency find screen");
        cout << "\nFind by: [1] Code or [2] Country\n";
        short Answer = 1;
        cin >> Answer;
        
        if (Answer == 1) {
            string CurrencyCode;
            cout << "Please enter CurrencyCode: ";
            CurrencyCode = clsInputValidate::ReadString();
            clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
            _ShowResult(Currency);
        } else {
            string CurrencyCountry;
            cout << "Please enter CurrencyCode: ";
            CurrencyCountry = clsInputValidate::ReadString();
            clsCurrency Currency = clsCurrency::FindByCountry(CurrencyCountry);
            _ShowResult(Currency);
        }
	}
};

