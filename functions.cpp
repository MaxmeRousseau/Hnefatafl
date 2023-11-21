#include <iostream>
#include <math.h>
using namespace std;

#include "functions.h"
#include "tests.h"


void clearConsole(){

#if defined (__WIN32__)
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences
#elif defined (__APPLE__)
    system("clear");
#endif
}

void clearUserInput(){
    cin.clear();
    cin.ignore(10000,'\n');
}

void displayHnefataflLogo(){

    //display cool logo
    cout <<"                           ...     ...           ..      .         .....               ..                  .....              .....                ..."<<endl;
    cout <<"         .xHL           .=*8888n..\"%888:      x88f` `..x88. .>  .H8888888x.  '`+    :**888H: `: .xH\"\"   .H8888888h.  ~-.   .H8888888x.  '`+    .zf\"` `\"tu   "<<endl;
    cout <<"      .-`8888hxxx~     X    ?8888f '8888    :8888   xf`*8888%  :888888888888x.  !  X   `8888k XX888     888888888888x  `> :888888888888x.  !  x88      '8N. "<<endl;
    cout <<"   .H8X  `%888*\"       88x. '8888X  8888>  :8888f .888  `\"`    8~    `\"*88888888\" '8hx  48888 ?8888    X~     `?888888hx~ 8~    `\"*88888888\"  888k     d88& "<<endl;
    cout <<"   888X     ..x..     '8888k 8888X  '\"*8h. 88888' X8888. >\"8x  !      .  `f\"\"\"\"   '8888 '8888 `8888    '      x8.^\"*88*\"  !      .  `f\"\"\"\"    8888N.  @888F "<<endl;
    cout <<"  '8888k .x8888888x    \"8888 X888X .xH8    88888  ?88888< 888>  ~:...-` :8L <)88:  %888>'8888  8888     `-:- X8888x        ~:...-` :8L <)88:  `88888 9888%  "<<endl;
    cout <<"   ?8888X    \"88888X     `8\" X888!:888X    88888   \"88888 \"8%      .   :888:>X88!    \"8 '888\"  8888          488888>          .   :888:>X88!    %888 \"88F   "<<endl;
    cout <<"    ?8888X    '88888>   =~`  X888 X888X    88888 '  `8888>      :~\"88x 48888X ^`    .-` X*\"    8888        .. `\"88*        :~\"88x 48888X ^`      8\"   \"*h=~ "<<endl;
    cout <<" H8H %8888     `8888>    :h. X8*` !888X    `8888> %  X88!      <  :888k'88888X        .xhx.    8888      x88888nX\"      . <  :888k'88888X      z8Weu        "<<endl;
    cout <<"'888> 888\"      8888    X888xX\"   '8888..:  `888X  `~\"\"`   :     d8888f '88888X     .H88888h.~`8888.>   !\"*8888888n..  :    d8888f '88888X    \"\"88888i.   Z "<<endl;
    cout <<" \"8` .8\" ..     88*   :~`888f     '*888*\"     \"88k.      .~     :8888!    ?8888>   .~  `%88!` '888*~   '    \"*88888888*    :8888!    ?8888>  \"   \"8888888* "<<endl;
    cout <<"    `  x8888h. d*\"        \"\"        `\"`         `\"\"*==~~`       X888!      8888~         `\"     \"\"             ^\"***\"`     X888!      8888~        ^\"**\"\"   "<<endl;
    cout <<"      !\"\"*888%~                                                 '888       X88f                                            '888       X88f                  "<<endl;
    cout <<"      !   `\"  .                                                  '%8:     .8*\"                                              '%8:     .8*\"                   "<<endl;
    cout <<"      '-....:~                                                      ^----~\"`                                                   ^----~\"`                     "<<endl<<endl<<endl;
}

bool chooseSizeBoard(BoardSize& aBoardSize){
    int playerBoardSize;
    cout << "Sur quel Plateau voulez-vous jouez ? 11 ou 13 : " << endl;
    cin >> playerBoardSize;
    aBoardSize = BoardSize(playerBoardSize);
    if(aBoardSize == LITTLE || aBoardSize == BIG) return true;
    return false;
}

void initializeBoard(Cell aBoard[][BOARD_SIZE_MAX], const BoardSize& aBoardSize){
    string boardDefaultState;
    int stringIterator = 0;
    switch (aBoardSize) {
        case LITTLE:
            boardDefaultState = smallBoard;
            break;
        case BIG:
            boardDefaultState = bigBoard;
            break;
        default:
            boardDefaultState = smallBoard;
            break;
    }

    for (int i = 0; i < aBoardSize; ++i) {
        for (int j = 0; j < aBoardSize; ++j) {
            if(boardDefaultState[stringIterator] == '0')
            {
                aBoard[i][j].itsPieceType = NONE;
                aBoard[i][j].itsCellType = NORMAL;
            }
            else if(boardDefaultState[stringIterator] == '1')
            {
                aBoard[i][j].itsPieceType = SWORD;
                aBoard[i][j].itsCellType = NORMAL;
            }
            else if(boardDefaultState[stringIterator] == '2')
            {
                aBoard[i][j].itsPieceType = SHIELD;
                aBoard[i][j].itsCellType = NORMAL;
            }
            else if(boardDefaultState[stringIterator] == 'X')
            {
                aBoard[i][j].itsPieceType = NONE;
                aBoard[i][j].itsCellType = FORTRESS;
            }
            else if(boardDefaultState[stringIterator] == '3')
            {
                aBoard[i][j].itsPieceType = KING;
                aBoard[i][j].itsCellType = CASTLE;
            }
            //+1 iterator
            stringIterator++;
        }
    }

}

void displayBoard(const Cell aBoard[][BOARD_SIZE_MAX], const BoardSize& aBoardSize){
    cout << "    ";
    for (int i = 0; i < aBoardSize; ++i) {
        //convert to char otherwise it will not have the expected result
        if(i<9){
           cout<<i+1<<"   ";
        }
        else cout <<i+1<<"  ";
    }
    cout << endl;

    //main loop
    for (int i = 0; i < aBoardSize; ++i)
    {
        //Display line according to the chosen size
        cout << "  +";
        for (int i = 0; i < aBoardSize; ++i)
        {
            cout << "---+";
        }

        //start of new line
        cout<< endl << char('A'+i) <<" | ";

//        if(i<9){
//            cout<<endl<<i+1<<" | ";
//        }
//        else cout <<endl<<i+1<<"| ";

        //loop for PieceType & CellType
        for (int j = 0; j < aBoardSize; ++j)
        {
            switch (aBoard[i][j].itsPieceType) {
                case NONE:
                    if(aBoard[i][j].itsCellType == CASTLE )
                    {
                        cout <<"C"<<" | ";
                    }
                    else if(aBoard[i][j].itsCellType == FORTRESS)
                    {
                        cout <<"F"<<" | ";
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
    for (int i = 0; i < aBoardSize; ++i)
    {
        cout << "---+";
    }
    cout << endl;
}

Position getPositionFromInput(){
    Position tempPos = {-1,-1};
    bool isValidC,isValidR;
    string userInput;
    int stringIterator = 1;
    //UserInput
    cout << "Selectionner une case (exemple B3) : " <<endl;
    cin >> userInput ;

    //get letter lowercase or uppercase
    if(userInput[0] >= 'A' && userInput[0] <= 'Z')
    {
        tempPos.itsRow = userInput[0]-65;
        isValidR = true;
    }
    else if(userInput[0] >= 'a' && userInput[0]<='z')
    {
            tempPos.itsRow = userInput[0]-97;
            isValidR = true;
    }
    else {isValidR = false;}

    //get number of items
    while (userInput[stringIterator] != '\0')
    {
        stringIterator++;
    }
    //loop on them backwards
    for (int i = stringIterator-1; i > 0; --i) {
        if (userInput[i] >= '0' && userInput[i] <= '9') {
            tempPos.itsCol += int(userInput[i] - '0') * pow(10, stringIterator - i - 1);
            isValidC = true;
        }
        else {
            isValidC = false;
            break;
        }
    }

    if (isValidR && isValidC){return tempPos;}
    else{return {-1,-1};}

}

bool isValidPosition(const Position& aPos, const BoardSize& aBoardSize){
    //Check the pos with the selected size to know if it's out of Bound
    //cout << "Valeur d'etree Row= " << aPos.itsRow << " Valeur d'etree Col= " << aPos.itsCol <<endl;
    if ((aPos.itsRow >= aBoardSize) || aPos.itsRow < 0 || (aPos.itsCol >= aBoardSize) || aPos.itsCol < 0)
    {
        return false;
    }
    return true;
}

bool isEmptyCell(const Cell aBoard[][BOARD_SIZE_MAX], const Position& aPos){
    if(aBoard[aPos.itsRow][aPos.itsCol].itsPieceType == NONE)
    {
        return true;
    }
    return false;
}

bool isValidMovement(const PlayerRole& aPlayer, const Cell aBoard[][BOARD_SIZE_MAX],const Position& aStartPos,const Position& aEndPos){
    Position direction{};
    //check empty cell
    if(isEmptyCell(aBoard,aStartPos))
    {
        cout<<"empty cell"<<endl; return false;
    }
    //check if the player don't input the same case twice
    if(aStartPos.itsRow == aEndPos.itsRow && aStartPos.itsCol == aEndPos.itsCol)
    {
        cout << "Same case !" <<endl;
        return false;
    }
    //check if the player take the good piece
    switch (aPlayer) {
        case ATTACK:
            if(aBoard[aStartPos.itsRow][aStartPos.itsCol].itsPieceType != SWORD)
            {
                cout << "wrong player !" <<endl;
                return false;
            }
            break;
        case DEFENSE:
            if(aBoard[aStartPos.itsRow][aStartPos.itsCol].itsPieceType != SHIELD && aBoard[aStartPos.itsRow][aStartPos.itsCol].itsPieceType != KING)
            {
                cout << "wrong player !" <<endl;
                return false;
            }
            break;
    }
    //check direction
    direction.itsCol = aStartPos.itsCol - aEndPos.itsCol;
    direction.itsRow = aStartPos.itsRow - aEndPos.itsRow;

    if (aStartPos.itsCol == aEndPos.itsCol){
        //check row
        if (direction.itsRow>0)
        {
            for (int i = aStartPos.itsRow-1; i >= aEndPos.itsRow; --i) {
                if (aBoard[i][aStartPos.itsCol].itsPieceType != NONE || aBoard[i][aStartPos.itsCol].itsCellType == FORTRESS && aBoard[aStartPos.itsRow][aStartPos.itsCol].itsPieceType != KING || aBoard[i][aStartPos.itsCol].itsCellType == CASTLE && aBoard[aStartPos.itsRow][aStartPos.itsCol].itsPieceType != KING){
                    cout << "Row>0 encuntered a piece at " << i<<":"<<aStartPos.itsCol <<endl;
                    return false;
                }
            }
        }
        if (direction.itsRow<0)
        {
            for (int i = aStartPos.itsRow+1; i <= aEndPos.itsRow; ++i) {
                if (aBoard[i][aStartPos.itsCol].itsPieceType != NONE || aBoard[i][aStartPos.itsCol].itsCellType == FORTRESS && aBoard[aStartPos.itsRow][aStartPos.itsCol].itsPieceType != KING || aBoard[i][aStartPos.itsCol].itsCellType == CASTLE && aBoard[aStartPos.itsRow][aStartPos.itsCol].itsPieceType != KING){
                    cout << "Row<0 encuntered a piece at " << i<<":"<<aStartPos.itsCol <<endl;
                    return false;
                }
            }
        }
    }
    else if (aStartPos.itsRow == aEndPos.itsRow){
        //check col
        if (direction.itsCol>0)
        {
            for (int i = aStartPos.itsCol-1; i >= aEndPos.itsCol; --i) {
                if (aBoard[aStartPos.itsRow][i].itsPieceType != NONE || aBoard[aStartPos.itsRow][i].itsCellType == FORTRESS && aBoard[aStartPos.itsRow][aStartPos.itsCol].itsPieceType != KING ||  aBoard[aStartPos.itsRow][i].itsCellType == CASTLE && aBoard[aStartPos.itsRow][aStartPos.itsCol].itsPieceType != KING){
                    cout << "Col>0 encuntered a piece at " << aStartPos.itsRow<<":"<<i <<endl;
                    return false;
                }
            }
        }
        if (direction.itsCol<0)
        {
            for (int i = aStartPos.itsCol+1; i <= aEndPos.itsCol; ++i) {
                if (aBoard[aStartPos.itsRow][i].itsPieceType != NONE || aBoard[aStartPos.itsRow][i].itsCellType == FORTRESS && aBoard[aStartPos.itsRow][aStartPos.itsCol].itsPieceType != KING || aBoard[aStartPos.itsRow][i].itsCellType == CASTLE && aBoard[aStartPos.itsRow][aStartPos.itsCol].itsPieceType != KING){
                    cout << "Col<0 encuntered a piece at " << aStartPos.itsRow<<":"<<i <<endl;
                    return false;
                }
            }
        }
    }
    else{
        //unvalid movment /!\ should not be reached
        cout << "Illegal move !" <<endl;
        return false;
    }
    return true;
}

void movePiece(Cell aBoard[][BOARD_SIZE_MAX], const Position& aStartPos, const Position& aEndPos) {
    aBoard[aEndPos.itsRow][aEndPos.itsCol].itsPieceType = aBoard[aStartPos.itsRow][aStartPos.itsCol].itsPieceType;
    aBoard[aStartPos.itsRow][aStartPos.itsCol].itsPieceType = NONE;
}

void capturePieces(const PlayerRole& aPlayer, Cell aBoard[][BOARD_SIZE_MAX], const BoardSize& aBoardSize, const Position& aEndPos){
    Position initPosToCheck[4] = {{aEndPos.itsRow,aEndPos.itsCol+1}, // Up cell
                                  {aEndPos.itsRow+1,aEndPos.itsCol}, // Right cell
                                  {aEndPos.itsRow,aEndPos.itsCol-1}, // Down cell
                                  {aEndPos.itsRow-1,aEndPos.itsCol}}; // Left cell
    Position toCheckPos[12]= {{initPosToCheck[0].itsRow-1,initPosToCheck[0].itsCol},{initPosToCheck[0].itsRow,initPosToCheck[0].itsCol+1},{initPosToCheck[0].itsRow+1,initPosToCheck[0].itsCol},
                             {initPosToCheck[1].itsRow,initPosToCheck[1].itsCol+1},{initPosToCheck[1].itsRow+1,initPosToCheck[1].itsCol},{initPosToCheck[1].itsRow,initPosToCheck[1].itsCol-1},
                             {initPosToCheck[2].itsRow-1,initPosToCheck[2].itsCol},{initPosToCheck[2].itsRow,initPosToCheck[2].itsCol-1},{initPosToCheck[2].itsRow+1,initPosToCheck[2].itsCol},
                              {initPosToCheck[3].itsRow,initPosToCheck[3].itsCol+1},{initPosToCheck[3].itsRow-1,initPosToCheck[3].itsCol},{initPosToCheck[3].itsRow,initPosToCheck[3].itsCol-1}};

    Position toCapture[4]={{},{},{},{}};

    //cout << "POS INIT: ROW " << aEndPos.itsRow << " COL " << aEndPos.itsCol << endl;
    //for (int i = 0; i < 12; ++i) {
        //cout << "ROW " <<toCheckPos[i].itsRow << " COL " << toCheckPos[i].itsCol <<endl;
        //cout << aBoard[toCheckPos[i].itsRow][toCheckPos[i].itsCol].itsPieceType <<endl;
    //}

    for (int i = 0; i < 4; ++i) {
        switch (aPlayer) {
            case ATTACK:
//                cout << endl << "cas " << i+1 <<endl;
//                cout <<"cas " <<0 +(i*3) <<" : TypePiece = "<< aBoard[toCheckPos[0 +(i*3)].itsRow][toCheckPos[0 +(i*3)].itsCol].itsPieceType <<" TypeCase = "<<aBoard[toCheckPos[0 +(i*3)].itsRow][toCheckPos[0 +(i*3)].itsCol].itsCellType <<endl;
//                cout <<"cas " <<1 +(i*3)<<" : TypePiece = "<< aBoard[toCheckPos[1 +(i*3)].itsRow][toCheckPos[1 +(i*3)].itsCol].itsPieceType <<" TypeCase = "<<aBoard[toCheckPos[1 +(i*3)].itsRow][toCheckPos[1 +(i*3)].itsCol].itsCellType <<endl;
//                cout <<"cas " <<2 +(i*3)<<" : TypePiece = "<< aBoard[toCheckPos[2 +(i*3)].itsRow][toCheckPos[2 +(i*3)].itsCol].itsPieceType <<" TypeCase = "<<aBoard[toCheckPos[2 +(i*3)].itsRow][toCheckPos[2 +(i*3)].itsCol].itsCellType <<endl;

                if((aBoard[toCheckPos[0 +(i*3)].itsRow][toCheckPos[0 +(i*3)].itsCol].itsPieceType == SWORD || aBoard[toCheckPos[0 +(i*3)].itsRow][toCheckPos[0 +(i*3)].itsCol].itsCellType == FORTRESS || (aBoard[toCheckPos[0 +(i*3)].itsRow][toCheckPos[0 +(i*3)].itsCol].itsCellType == CASTLE && aBoard[toCheckPos[0 +(i*3)].itsRow][toCheckPos[0 +(i*3)].itsCol].itsPieceType != KING)||
                    aBoard[toCheckPos[1 +(i*3)].itsRow][toCheckPos[1 +(i*3)].itsCol].itsPieceType == SWORD || aBoard[toCheckPos[1 +(i*3)].itsRow][toCheckPos[1 +(i*3)].itsCol].itsCellType == FORTRESS || (aBoard[toCheckPos[1 +(i*3)].itsRow][toCheckPos[1 +(i*3)].itsCol].itsCellType == CASTLE && aBoard[toCheckPos[1 +(i*3)].itsRow][toCheckPos[1 +(i*3)].itsCol].itsPieceType != KING)||
                    aBoard[toCheckPos[2 +(i*3)].itsRow][toCheckPos[2 +(i*3)].itsCol].itsPieceType == SWORD || aBoard[toCheckPos[2 +(i*3)].itsRow][toCheckPos[2 +(i*3)].itsCol].itsCellType == FORTRESS || (aBoard[toCheckPos[2 +(i*3)].itsRow][toCheckPos[2 +(i*3)].itsCol].itsCellType == CASTLE && aBoard[toCheckPos[2 +(i*3)].itsRow][toCheckPos[2 +(i*3)].itsCol].itsPieceType != KING))
                    && aBoard[initPosToCheck[i].itsRow][initPosToCheck[i].itsCol].itsPieceType == SHIELD)
                {
                    //cout << "capture shield" <<endl;
                    toCapture[i] = initPosToCheck[i];
                }
                else{toCapture[i] = {-1,-1};}
                break;
            case DEFENSE:
//                cout << endl << "cas " << i+1 <<endl;
//                cout <<"cas " <<0 +(i*3) <<" : TypePiece = "<< aBoard[toCheckPos[0 +(i*3)].itsRow][toCheckPos[0 +(i*3)].itsCol].itsPieceType <<" TypeCase = "<<aBoard[toCheckPos[0 +(i*3)].itsRow][toCheckPos[0 +(i*3)].itsCol].itsCellType <<endl;
//                cout <<"cas " <<1 +(i*3)<<" : TypePiece = "<< aBoard[toCheckPos[1 +(i*3)].itsRow][toCheckPos[1 +(i*3)].itsCol].itsPieceType <<" TypeCase = "<<aBoard[toCheckPos[1 +(i*3)].itsRow][toCheckPos[1 +(i*3)].itsCol].itsCellType <<endl;
//                cout <<"cas " <<2 +(i*3)<<" : TypePiece = "<< aBoard[toCheckPos[2 +(i*3)].itsRow][toCheckPos[2 +(i*3)].itsCol].itsPieceType <<" TypeCase = "<<aBoard[toCheckPos[2 +(i*3)].itsRow][toCheckPos[2 +(i*3)].itsCol].itsCellType <<endl;

                if((aBoard[toCheckPos[0 +(i*3)].itsRow][toCheckPos[0 +(i*3)].itsCol].itsPieceType == KING ||aBoard[toCheckPos[0 +(i*3)].itsRow][toCheckPos[0 +(i*3)].itsCol].itsPieceType == SHIELD || aBoard[toCheckPos[0 +(i*3)].itsRow][toCheckPos[0 +(i*3)].itsCol].itsCellType == FORTRESS || aBoard[toCheckPos[0 +(i*3)].itsRow][toCheckPos[0 +(i*3)].itsCol].itsCellType == CASTLE ||
                    aBoard[toCheckPos[1 +(i*3)].itsRow][toCheckPos[1 +(i*3)].itsCol].itsPieceType == KING ||aBoard[toCheckPos[1 +(i*3)].itsRow][toCheckPos[1 +(i*3)].itsCol].itsPieceType == SHIELD || aBoard[toCheckPos[1 +(i*3)].itsRow][toCheckPos[1 +(i*3)].itsCol].itsCellType == FORTRESS || aBoard[toCheckPos[1 +(i*3)].itsRow][toCheckPos[1 +(i*3)].itsCol].itsCellType == CASTLE ||
                    aBoard[toCheckPos[2 +(i*3)].itsRow][toCheckPos[2 +(i*3)].itsCol].itsPieceType == KING ||aBoard[toCheckPos[2 +(i*3)].itsRow][toCheckPos[2 +(i*3)].itsCol].itsPieceType == SHIELD || aBoard[toCheckPos[2 +(i*3)].itsRow][toCheckPos[2 +(i*3)].itsCol].itsCellType == FORTRESS || aBoard[toCheckPos[2 +(i*3)].itsRow][toCheckPos[2 +(i*3)].itsCol].itsCellType == CASTLE)
                    && aBoard[initPosToCheck[i].itsRow][initPosToCheck[i].itsCol].itsPieceType == SWORD)
                {
                    //cout << "capture sword" <<endl;
                    toCapture[i] = initPosToCheck[i];
                }
                else{toCapture[i] = {-1,-1};}
                break;
        }
    }

    for (int i = 0; i < 4; ++i)
    {
        if(toCapture[i].itsRow != -1 && toCapture[i].itsCol != -1)
        {
            aBoard[toCapture[i].itsRow][toCapture[i].itsCol].itsPieceType = NONE;
        }
    }
}

bool isSwordLeft(const Cell aBoard[][BOARD_SIZE_MAX], const BoardSize& aBoardSize){
    for (int i = 0; i < aBoardSize; ++i) {
        for (int j = 0; j < aBoardSize; ++j) {
            if (aBoard[i][j].itsPieceType == SWORD){return true;}
        }
    }

    return false;
}

int playGame(){
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

    Position userInput1 , userInput2;
    do{
        do{
            cout << "Etrée la coordonée de la pièce a bougé" <<endl;
            userInput1 = getPositionFromInput();
        }while(isValidPosition(userInput1,sizeChosen));
        do{
            cout << "Etrée la coordonée de la case d'arrivé" <<endl;
            userInput2 = getPositionFromInput();
        }while(isValidPosition(userInput2,sizeChosen));
    }while(!isValidMovement(ATTACK,gameBoard,userInput1,userInput2));

    movePiece(gameBoard,userInput1,userInput2);
    //clearConsole();
    //displayHnefataflLogo();
    displayBoard(gameBoard,sizeChosen);

    //Try to move a piece
    //cout << isValidMovement(ATTACK,gameBoard,{3,0},{3,4}) << endl;
    //movePiece(gameBoard,{3,0},{3,4});
    //displayBoard(gameBoard,sizeChosen);


    return 0;
}

void launchTests(){
    //test_chooseSizeBoard(); //PASSED
    //test_initializeBoard(); //PASSED
    //test_getPositionFromInput(); //PASSED
    //test_isValidPosition(); //PASSED
    //test_isEmptyCell(); //PASSED
    //test_isValidMovement(); //PASSED
    //test_movePiece(); //PASSED
    //test_capturePieces();
    test_isSwordLeft();


}