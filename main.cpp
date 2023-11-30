#include <iostream>
using namespace std;

#include "typeDef.h"
#include "functions.h"



int main()
{
    string choice = "y";
    cout << "Lancer les test ? y/n \nou lancer le cas par cas ? c"<<endl;
    cin >> choice;
    clearUserInput();
    if (choice == "y"){
        clearConsole();
        launchTests();
    }
    else if (choice == "c"){

    }
    playGame();
    return 0;
}

