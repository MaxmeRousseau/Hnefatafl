#include <iostream>
#include "typeDef.h"

using namespace std;

int main()
{
    //GameBoard at 13x13 (max size)
    Cell gameBoard [BOARD_SIZE_MAX] [BOARD_SIZE_MAX];

    //default board
    string choosenBoard = smallBoard;
    //iterator for board strings
    int initBoardI = 0;


    //ask Board Size
    int playerBoardSize;
    //default size
    BoardSize sizeChoosen = LITTLE;
    cout << "Sur quel Plateau voulez vous jouez ? 11 ou 13 : " << endl;
    cin >> playerBoardSize;
    if(playerBoardSize == 13)
    {
        sizeChoosen = BIG;
        choosenBoard = bigBoard;
    }
    // if the player enter anything other than 13 the small is the default board


    //Init default Board state
    for (int i = 0; i < sizeChoosen; ++i)
    {
        for (int j = 0; j < sizeChoosen; ++j)
        {
            if(choosenBoard[initBoardI] == '0')
            {
                gameBoard[i][j].itsPieceType = NONE;
                gameBoard[i][j].itsCellType = NORMAL;
            }
            else if(choosenBoard[initBoardI] == '1')
            {
                gameBoard[i][j].itsPieceType = SWORD;
                gameBoard[i][j].itsCellType = NORMAL;
            }
            else if(choosenBoard[initBoardI] == '2')
            {
                gameBoard[i][j].itsPieceType = SHIELD;
                gameBoard[i][j].itsCellType = NORMAL;
            }
            else if(choosenBoard[initBoardI] == 'X')
            {
                gameBoard[i][j].itsPieceType = NONE;
                gameBoard[i][j].itsCellType = FORTRESS;
            }
            else if(choosenBoard[initBoardI] == '3')
            {
                gameBoard[i][j].itsPieceType = KING;
                gameBoard[i][j].itsCellType = CASTLE;
            }

            //+1 on string
            initBoardI++;
        }
        cout << endl;
    }

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
        //Display line according to the choosen size
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
