#include <iostream>
using namespace std;

#include "typeDef.h"
#include "functions.h"



int main()
{
    string choice = "y";
    cout << "Lancer les test ? y/n"<<endl;
    cin >> choice;
    clearUserInput();
    if (choice == "y"){
        clearConsole();
        launchTests();
    }
    playGame();
    return 0;
}

