
// Bank project

#include <iostream>
#include "clsMainScreen.h";
#include "clsLoginScreen.h";
#include "clsCurrency.h";

using namespace std;

int main() {

    //clsMainScreen::ShowMainMenu();

    while (true) {
        if (!clsLoginScreen::ShowLoginScreen());
        break;
    }

    system("pause>0");
    return 0;
}