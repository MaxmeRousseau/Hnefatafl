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
    BoardSize sizeChoosen;
    clearConsole();
    do
    {
        clearUserInput(); // Clear userInput
        clearConsole();
        cout << "Sur quel Plateau voulez vous jouez ? 11 ou 13 : " << endl;
        cin >> playerBoardSize;
        sizeChoosen = BoardSize(playerBoardSize);
    }
    while(!chooseSizeBoard(sizeChoosen));


    initializeBoard(gameBoard,sizeChoosen);
    clearConsole();
    displayHnefataflLogo();


    //AffichTab

    //Letters (max 'Z')
    cout << "    ";
    for (int i = 0; i < sizeChoosen; ++i) {
        //convert to char otherwise it will not have the expected result
        cout << char('A'+i) << "   ";
    }
    cout << endl;

    //main loop
    for (int i = 0; i < sizeChoosen; ++i)
    {
        //Display line according to the chosen size
        cout << "  +";
        for (int i = 0; i < sizeChoosen; ++i)
        {
            cout << "---+";
        }

        //start of new line
        if(i<9){
            cout<<endl<<i+1<<" | ";
        }
        else cout <<endl<<i+1<<"| ";

        //loop for PieceType & CellType
        for (int j = 0; j < sizeChoosen; ++j)
        {
            switch (gameBoard[i][j].itsPieceType) {
            case NONE:
                if(gameBoard[i][j].itsCellType == CASTLE || gameBoard[i][j].itsCellType == FORTRESS)
                {
                    cout <<"X"<<" | ";
                }
                else cout<< " " << " | ";
                break;
            case SHIELD:
                cout << "@"<<" | ";
                break;
            case SWORD:
                cout << "/"<<" | ";
                break;
            case KING:
                cout <<"W" << " | ";
                break;
            }
        }
        //next line
        cout << endl;
    }

    //end line
    cout << "  +";
    for (int i = 0; i < sizeChoosen; ++i)
    {
        cout << "---+";
    }
    cout << endl;

    //Explain each symbols
    cout << endl << "Sword : " <<"/" << " Shield: " << "@" << " King: " << "W"<< " Forteress : X"<< endl;

    return 0;
}
