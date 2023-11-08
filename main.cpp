#include <iostream>
#include "typeDef.h"
#include "functions.cpp"

using namespace std;

int main()
{
    //GameBoard at 13x13 (max size)
    Cell gameBoard [BOARD_SIZE_MAX] [BOARD_SIZE_MAX];

    //default board
    string choosenBoard;

    //iterator for board strings
    //int initBoardI = 0;


    //ask Board Size
    int playerBoardSize;
    BoardSize sizeChosen;
    clearConsole();
    do
    {
        clearUserInput(); // Clear userInput
        clearConsole();
        cout << "Sur quel Plateau voulez vous jouez ? 11 ou 13 : " << endl;
        cin >> playerBoardSize;
        sizeChosen = BoardSize(playerBoardSize);
    }
    while(!chooseSizeBoard(sizeChosen));

    //Test function
    initializeBoard(gameBoard,sizeChosen);
    clearConsole();
    displayHnefataflLogo();
    
    displayBoard(gameBoard,sizeChosen);

    //Explain each symbols
    cout << endl << "Sword : " <<"/" << " Shield: " << "@" << " King: " << "W"<< " Forteress : X"<< endl;

    return 0;
}
