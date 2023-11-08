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

    //ask Board Size
    int playerBoardSize;
    BoardSize sizeChosen;
    do
    {
        clearConsole();
        cout << "Sur quel Plateau voulez vous jouez ? 11 ou 13 : " << endl;
        cin >> playerBoardSize;
        sizeChosen = BoardSize(playerBoardSize);
        clearUserInput(); // Clear userInput
    }
    while(!chooseSizeBoard(sizeChosen));

    //Test function
    initializeBoard(gameBoard,sizeChosen);
    clearConsole();
    displayHnefataflLogo();
    
    displayBoard(gameBoard,sizeChosen);

    //Explain each symbols
    cout << endl << "Sword : " <<"/" << " Shield: " << "@" << " King: " << "W"<< " Forteress : X"<< endl;

    //testPos
//    Position testpos;
//    testpos = getPositionFromInput();
//    cout << testpos.itsRow << " " << testpos.itsCol << gameBoard[testpos.itsCol][testpos.itsRow].itsPieceType <<endl;

    cout << isValidMovement(ATTACK,gameBoard,{3,0},{3,4}) << endl;
    movePiece(gameBoard,{3,0},{3,4});
    displayBoard(gameBoard,sizeChosen);
    return 0;
}
