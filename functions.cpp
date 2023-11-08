#include <iostream>
#include "functions.h"

using namespace std;

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
        cout << char('A'+i) << "   ";
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
        if(i<9){
            cout<<endl<<i+1<<" | ";
        }
        else cout <<endl<<i+1<<"| ";

        //loop for PieceType & CellType
        for (int j = 0; j < aBoardSize; ++j)
        {
            switch (aBoard[i][j].itsPieceType) {
                case NONE:
                    if(aBoard[i][j].itsCellType == CASTLE || aBoard[i][j].itsCellType == FORTRESS)
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
    //UserInput
    cout << "Selectionner une case (exemple B3) : " <<endl;
    clearUserInput();
    cin >> userInput ;

    if(userInput[0] >= 'A' && userInput[0] <= 'M')
    {
        tempPos.itsCol = userInput[0]-65;
        isValidC = true;
    }
    else {isValidC = false;}

    if(userInput[1]>='1' && userInput[1]<='9' && userInput[2] == '\0' )
    {
        tempPos.itsRow = int(userInput[1] - '1');
        isValidR = true;
    }
    //prend seulement 13 et 10
    else if(userInput[1]=='1' && userInput[2] <= '3' && userInput[2] >= '0')
    {
        tempPos.itsRow = int((userInput[1]-'0')*10 +int(userInput[2]-'0')) - 1;
        isValidR = true;
    }
    else {isValidR = false;}

    if (isValidR && isValidC){return tempPos;}
    else{return {-1,-1};}

}

bool isValidPosition(const Position& aPos, const BoardSize& aBoardSize){
    //Check the pos with the selected size to know if it's out of Bound
    if (aPos.itsRow>aBoardSize || aPos.itsRow< 0 || aPos.itsCol > aBoardSize || aPos.itsCol < 0)
    {
        return false;
    }
    return true;
}

bool isEmptyCell(const Cell aBoard[][BOARD_SIZE_MAX], const Position& aPos){
    if(aBoard[aPos.itsCol][aPos.itsRow].itsPieceType == NONE)
    {
        return true;
    }
    return false;
}

bool isValidMovement(const PlayerRole& aPlayer, const Cell aBoard[][BOARD_SIZE_MAX],const Position& aStartPos,const Position& aEndPos){
    Position direction{};
    //check empty cell
    if(isEmptyCell(aBoard,aStartPos)){return false;}
    //check if the player don't input the same case twice
    if(aStartPos.itsRow == aEndPos.itsRow && aStartPos.itsCol == aEndPos.itsCol){return false;}
    //check if the player take the good piece
    switch (aPlayer) {
        case ATTACK:
            if(aBoard[aStartPos.itsCol][aStartPos.itsRow].itsPieceType != SWORD)
            {
                return false;
            }
            break;
        case DEFENSE:
            if(aBoard[aStartPos.itsCol][aStartPos.itsRow].itsPieceType != SHIELD && aBoard[aStartPos.itsCol][aStartPos.itsRow].itsPieceType != KING)
            {
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
            for (int i = aStartPos.itsRow; i <= aEndPos.itsRow; ++i) {
                if (aBoard[aStartPos.itsCol][i].itsPieceType != NONE){
                    return false;
                }
            }
        }
        if (direction.itsRow<0)
        {
            for (int i = aStartPos.itsRow; i >= aEndPos.itsRow; --i) {
                if (aBoard[aStartPos.itsCol][i].itsPieceType != NONE){
                    return false;
                }
            }
        }
    }
    else if (aStartPos.itsRow == aEndPos.itsRow){
        //check col
        if (direction.itsCol>0)
        {
            for (int i = aStartPos.itsCol; i <= aEndPos.itsCol; ++i) {
                if (aBoard[i][aStartPos.itsRow].itsPieceType != NONE){
                    return false;
                }
            }
        }
        if (direction.itsCol<0)
        {
            for (int i = aStartPos.itsCol; i >= aEndPos.itsCol; --i) {
                if (aBoard[i][aStartPos.itsRow].itsPieceType != NONE){
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
    aBoard[aEndPos.itsCol][aEndPos.itsRow].itsPieceType = aBoard[aStartPos.itsCol][aStartPos.itsRow].itsPieceType;
    aBoard[aStartPos.itsCol][aStartPos.itsRow].itsPieceType = NONE;
}

