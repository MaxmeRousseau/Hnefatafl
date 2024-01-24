#include <iostream>
using namespace std;
#include "caseByCase.h"
#include "typeDef.h"
#include "functions.h"


void cbcCaptureKing(){
    Cell gameBoard [BOARD_SIZE_MAX] [BOARD_SIZE_MAX];
    BoardSize sizeChosen = LITTLE;
    PlayerRole turnPlayer = ATTACK;
    Position startPos{} , endPos{};

    for (int i = 0; i < LITTLE; ++i) {
        for (int j = 0; j < LITTLE; ++j) {
            gameBoard[i][j].itsPieceType = NONE;
            gameBoard[i][j].itsCellType = NORMAL;
        }
    }
    gameBoard[0][0].itsCellType = FORTRESS;
    gameBoard[0][LITTLE-1].itsCellType = FORTRESS;
    gameBoard[LITTLE-1][0].itsCellType = FORTRESS;
    gameBoard[LITTLE-1][LITTLE-1].itsCellType = FORTRESS;

    gameBoard[0][5].itsPieceType = KING;
    gameBoard[0][4].itsPieceType = SWORD;
    gameBoard[0][6].itsPieceType = SWORD;
    gameBoard[5][5].itsPieceType = SWORD;

    //Game loop
    do{
        //Display Board
        clearConsole();
        displayHnefataflLogo();
        displayBoard(gameBoard,sizeChosen);
        cout << "-----------CaseByCase CaptureKing----------" <<endl;

        switch (turnPlayer) {

            case ATTACK:
                cout << "Au tour des Attaquant" << endl;
                cout << "Selectionner une case (exemple B3) : " <<endl;
                break;
            case DEFENSE:
                cout << "Au tour des Défenseur " << endl;
                cout << "Selectionner une case (exemple B3) : " <<endl;
                break;
        }
        //Move Pieces
        do{
            do{
                clearUserInput();
                cout << "Etrée la coordonée de la pièce a bouger" <<endl;
                startPos = getPositionFromInput();
            }while(!isValidPosition(startPos,sizeChosen));
            do{
                clearUserInput();
                cout << "Etrée la coordonée de la case d'arrivé" <<endl;
                endPos = getPositionFromInput();
            }while(!isValidPosition(endPos,sizeChosen));
        }while(!isValidMovement(turnPlayer,gameBoard,startPos,endPos));

        movePiece(gameBoard,startPos,endPos);
        capturePieces(turnPlayer,gameBoard,sizeChosen,endPos);
        displayBoard(gameBoard,sizeChosen); // in case of last move

    } while (isSwordLeft(gameBoard,sizeChosen) && !isKingCaptured(gameBoard,sizeChosen) && !isKingEscaped(gameBoard,sizeChosen));
}

void cbcCapturePiece(){
    Cell gameBoard [BOARD_SIZE_MAX] [BOARD_SIZE_MAX];
    BoardSize sizeChosen = LITTLE;
    PlayerRole turnPlayer = DEFENSE;
    Position startPos{} , endPos{};

    for (int i = 0; i < LITTLE; ++i) {
        for (int j = 0; j < LITTLE; ++j) {
            gameBoard[i][j].itsPieceType = NONE;
            gameBoard[i][j].itsCellType = NORMAL;
        }
    }
    gameBoard[0][0].itsCellType = FORTRESS;
    gameBoard[0][LITTLE-1].itsCellType = FORTRESS;
    gameBoard[LITTLE-1][0].itsCellType = FORTRESS;
    gameBoard[LITTLE-1][LITTLE-1].itsCellType = FORTRESS;

    gameBoard[7][LITTLE-1].itsPieceType = KING;
    gameBoard[0][4].itsPieceType = SHIELD;
    gameBoard[0][7].itsPieceType = SHIELD;
    gameBoard[0][5].itsPieceType = SWORD;

    //Game loop
    do{
        //Display Board
        clearConsole();
        displayHnefataflLogo();
        displayBoard(gameBoard,sizeChosen);
        cout << "-----------CaseByCase CapturePiece----------" <<endl;

        switch (turnPlayer) {

            case ATTACK:
                cout << "Au tour des Attaquant" << endl;
                cout << "Selectionner une case (exemple B3) : " <<endl;
                break;
            case DEFENSE:
                cout << "Au tour des Défenseur " << endl;
                cout << "Selectionner une case (exemple B3) : " <<endl;
                break;
        }
        //Move Pieces
        do{
            do{
                clearUserInput();
                cout << "Etrée la coordonée de la pièce a bouger" <<endl;
                startPos = getPositionFromInput();
            }while(!isValidPosition(startPos,sizeChosen));
            do{
                clearUserInput();
                cout << "Etrée la coordonée de la case d'arrivé" <<endl;
                endPos = getPositionFromInput();
            }while(!isValidPosition(endPos,sizeChosen));
        }while(!isValidMovement(turnPlayer,gameBoard,startPos,endPos));

        movePiece(gameBoard,startPos,endPos);
        capturePieces(turnPlayer,gameBoard,sizeChosen,endPos);
        displayBoard(gameBoard,sizeChosen); // in case of last move

    } while (isSwordLeft(gameBoard,sizeChosen) && !isKingCaptured(gameBoard,sizeChosen) && !isKingEscaped(gameBoard,sizeChosen));
}

void cbcEscape(){
    Cell gameBoard [BOARD_SIZE_MAX] [BOARD_SIZE_MAX];
    BoardSize sizeChosen = LITTLE;
    PlayerRole turnPlayer = DEFENSE;
    Position startPos{} , endPos{};

    for (int i = 0; i < LITTLE; ++i) {
        for (int j = 0; j < LITTLE; ++j) {
            gameBoard[i][j].itsPieceType = NONE;
            gameBoard[i][j].itsCellType = NORMAL;
        }
    }
    gameBoard[0][0].itsCellType = FORTRESS;
    gameBoard[0][LITTLE-1].itsCellType = FORTRESS;
    gameBoard[LITTLE-1][0].itsCellType = FORTRESS;
    gameBoard[LITTLE-1][LITTLE-1].itsCellType = FORTRESS;

    gameBoard[7][LITTLE-1].itsPieceType = KING;
    gameBoard[0][5].itsPieceType = SWORD;

    //Game loop
    do{
        //Display Board
        clearConsole();
        displayHnefataflLogo();
        displayBoard(gameBoard,sizeChosen);
        cout << "-----------CaseByCase Escape----------" <<endl;

        switch (turnPlayer) {

            case ATTACK:
                cout << "Au tour des Attaquant" << endl;
                cout << "Selectionner une case (exemple B3) : " <<endl;
                break;
            case DEFENSE:
                cout << "Au tour des Défenseur " << endl;
                cout << "Selectionner une case (exemple B3) : " <<endl;
                break;
        }
        //Move Pieces
        do{
            do{
                clearUserInput();
                cout << "Etrée la coordonée de la pièce a bouger" <<endl;
                startPos = getPositionFromInput();
            }while(!isValidPosition(startPos,sizeChosen));
            do{
                clearUserInput();
                cout << "Etrée la coordonée de la case d'arrivé" <<endl;
                endPos = getPositionFromInput();
            }while(!isValidPosition(endPos,sizeChosen));
        }while(!isValidMovement(turnPlayer,gameBoard,startPos,endPos));

        movePiece(gameBoard,startPos,endPos);
        capturePieces(turnPlayer,gameBoard,sizeChosen,endPos);
        displayBoard(gameBoard,sizeChosen); // in case of last move

    } while (isSwordLeft(gameBoard,sizeChosen) && !isKingCaptured(gameBoard,sizeChosen) && !isKingEscaped(gameBoard,sizeChosen));

}
