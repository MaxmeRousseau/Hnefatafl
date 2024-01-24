#include <iostream>
using namespace std;

#include "typeDef.h"
#include "functions.h"
#include "caseByCase.h"



int main()
{
    string choice = "c";
    cout << "Lancer les test ? y/n \nou lancer le cas par cas ? c"<<endl;
    cin >> choice;
    if (choice == "y"){
        clearConsole();
        launchTests();
    }
    else if (choice == "c"){
        cbcCaptureKing();
        clearConsole();
        cbcCapturePiece();
        clearConsole();
        cbcEscape();
        clearConsole();
    }
    clearConsole();
    cout << endl;
    playGame();
    return 0;
}

