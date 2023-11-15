/**
 * @file tests.cpp
 *
 * @brief Implementation of test functions for testing the fonctions implemented in 'fonctions.cpp'.
 *
 * This file contains the implementation of test functions used to verify and validate
 * the functionality of the functions implemented in 'fonctions.cpp.'
 * These test functions are designed to thoroughly test various aspects of the code
 * in 'fonctions.cpp' to ensure that it performs as expected.
 * They cover a range of scenarios and edge cases, helping to identify and resolve
 * any potential issues or bugs in the codebase.
 * The tests are conducted on different board sizes and configurations,
 * providing comprehensive coverage to guarantee the reliability and correctness
 * of the functions in 'fonctions.cpp.'
 * Overall, 'test.cpp' plays a crucial role in maintaining code quality and robustness by confirming
 * that the functions it tests meet their intended specifications."
 *
 * @author JMB - IUT Informatique La Rochelle
 * @date 03/10/2023
 */

#include <iostream>
#include <sstream>

#include "typeDef.h"
#include "functions.h"

using namespace std;

/**
 * @brief Reset the game board to its initial state.
 *
 * This function initializes the game board by setting all cells to a normal state with no pieces.
 *
 * @param aBoard The game board to reset.
 * @param aBoardSize The size of the game board.
 */
void resetBoard(Cell aBoard[][BOARD_SIZE_MAX], const BoardSize& aBoardSize)
{
    // Iterate over each row and column of the board
    for (int i = 0; i < aBoardSize; ++i) {
        for (int j = 0; j < aBoardSize; ++j) {
            // Set the cell to a normal state with no piece
            aBoard[i][j] = {NORMAL, NONE};
        }
    }
}

/**
 * @brief Test function for the chooseSizeBoard function.
 *
 * This function tests the chooseSizeBoard function by simulating user input and
 * checking the returned values.
 */
void test_chooseSizeBoard()
{
    cout << "********* Start testing of chooseSizeBoard *********" << endl;
    int pass = 0; // Count of tests passed
    int failed = 0; // Count of tests failed

    // Redirect std::cin to a stringstream 'input'
    stringstream input;
    streambuf* OldBuf = cin.rdbuf(input.rdbuf());

    BoardSize yourBoardSize; // Variable to store the selected board size

    // Test 1: Simulate user input "11"
    input << "11\n";
    if (chooseSizeBoard(yourBoardSize) && yourBoardSize == LITTLE)
    {
        cout << endl << "PASS \t: " << "11" << endl << endl;
        pass++;
    }
    else
    {
        cout << endl <<  "FAIL! \t: " << "\n\tActual false " << yourBoardSize << "\n\texpected true and 11" << endl << endl;
        failed++;
    }

    // Test 2: Simulate user input "13"
    input << "13\n";
    if (chooseSizeBoard(yourBoardSize) && yourBoardSize == BIG)
    {
        cout << endl << "PASS \t: " << "13" << endl << endl;
        pass++;
    }
    else
    {
        cout << endl <<  "FAIL! \t: " << "\n\tActual false" << yourBoardSize << "\n\texpected true and 13" << endl << endl;
        failed++;
    }

    // Test 3: Simulate user input "12"
    input << "12\n";
    if (!chooseSizeBoard(yourBoardSize))
    {
        cout << endl << "PASS \t: " << "12" << endl << endl;
        pass++;
    }
    else
    {
        cout << endl <<  "FAIL! \t: " << "\n\tActual true" << "\n\texpected false" << endl;
        failed++;
    }

    // Test 4: Simulate user input "2d" (invalid input)
    input << "2d\n";
    if (!chooseSizeBoard(yourBoardSize))
    {
        cout << endl << "PASS \t: " << "2d" << endl << endl;
        pass++;
    }
    else
    {
        cout << endl <<  "FAIL! \t: " << "\n\tActual true" << "\n\texpected false" << endl << endl;
        failed++;
    }

    // Restore the initial streambuf of std::cin (output to console)
    cin.rdbuf(OldBuf);

    // Display test results
    cout << "Totals: " << pass << " passed, " << failed << " failed" << endl;
    cout << "********* Finished testing of chooseSizeBoard *********" << endl << endl;
}

/**
 * @brief Test function for the initializeBoard function.
 *
 * This function tests the initializeBoard function by comparing the generated board with expected board configurations.
 */
void test_initializeBoard()
{
    cout << "********* Start testing of initializeBoard *********" << endl;
    int pass = 0; // Count of tests passed
    int failed = 0; // Count of tests failed

    // Test on a small board
    Cell bLittle[BOARD_SIZE_MAX][BOARD_SIZE_MAX];
    BoardSize little = LITTLE;

    // Initialize the board with empty cells
    resetBoard(bLittle, little);

    // Set positions for fortresses (exits)
    bLittle[0][0].itsCellType = FORTRESS;
    bLittle[0][little-1].itsCellType = FORTRESS;
    bLittle[little-1][0].itsCellType = FORTRESS;
    bLittle[little-1][little-1].itsCellType = FORTRESS;

    // Set positions for the king and castle
    Position kingPos = { (little - 1) / 2, (little - 1) / 2 };
    bLittle[kingPos.itsRow][kingPos.itsCol] = {CASTLE, KING};

    // Set positions for shields (defenders)
    Position shieldsPositionsLittle[] = {
            { kingPos.itsRow - 1, kingPos.itsCol },
            { kingPos.itsRow + 1, kingPos.itsCol },
            { kingPos.itsRow, kingPos.itsCol - 1 },
            { kingPos.itsRow, kingPos.itsCol + 1 },
            { kingPos.itsRow - 1, kingPos.itsCol - 1 },
            { kingPos.itsRow + 1, kingPos.itsCol + 1 },
            { kingPos.itsRow - 1, kingPos.itsCol + 1 },
            { kingPos.itsRow + 1, kingPos.itsCol - 1 },
            { kingPos.itsRow - 2, kingPos.itsCol },
            { kingPos.itsRow + 2, kingPos.itsCol },
            { kingPos.itsRow, kingPos.itsCol - 2 },
            { kingPos.itsRow, kingPos.itsCol + 2 },
    };

    for (const Position& pos : shieldsPositionsLittle) {
        bLittle[pos.itsRow][pos.itsCol].itsPieceType = SHIELD;
    }

    // Set positions for swords (attackers)
    Position swordsPositionsLittle[] = {
            { kingPos.itsRow, 0 },
            { kingPos.itsRow - 1, 0 },
            { kingPos.itsRow - 2, 0 },
            { kingPos.itsRow + 1, 0 },
            { kingPos.itsRow + 2, 0 },
            { kingPos.itsRow, 1 },
            { kingPos.itsRow, little-1},
            { kingPos.itsRow - 1, little-1 },
            { kingPos.itsRow - 2, little-1 },
            { kingPos.itsRow + 1, little-1 },
            { kingPos.itsRow + 2, little-1 },
            { kingPos.itsRow, little-2 },
            { 0, kingPos.itsCol },
            { 0, kingPos.itsCol - 1 },
            { 0, kingPos.itsCol - 2 },
            { 0, kingPos.itsCol + 1 },
            { 0, kingPos.itsCol + 2 },
            { 1, kingPos.itsCol },
            { little-1, kingPos.itsCol },
            { little-1, kingPos.itsCol - 1 },
            { little-1, kingPos.itsCol - 2 },
            { little-1, kingPos.itsCol + 1 },
            { little-1, kingPos.itsCol + 2 },
            { little-2, kingPos.itsCol },
    };

    for (const Position& pos : swordsPositionsLittle) {
        bLittle[pos.itsRow][pos.itsCol].itsPieceType = SWORD;
    }

    Cell yourLittleBoard[BOARD_SIZE_MAX][BOARD_SIZE_MAX];
    initializeBoard(yourLittleBoard, little);

    // Compare the generated board with the expected configuration
    for (int i = 0; i < little; ++i) {
        for (int j = 0; j < little; ++j) {
            if (yourLittleBoard[i][j].itsCellType != bLittle[i][j].itsCellType
                || yourLittleBoard[i][j].itsPieceType != bLittle[i][j].itsPieceType)
            {
                failed++;
            }
        }
    }
    if (failed) {
        cout << "FAIL ! \t: " << failed << " different cases" << endl;
        cout << endl << "\tActual " << endl;
        displayBoard(yourLittleBoard, little);
        cout << endl << "\tExpected " << endl;
        displayBoard(bLittle, little);
        cout << endl;
    }
    else
    {
        cout << "PASS ! \t: " << endl;
        displayBoard(yourLittleBoard, little);
        cout << endl;
        pass++;
    }

    // Test on a big board
    Cell bBig[BOARD_SIZE_MAX][BOARD_SIZE_MAX];
    BoardSize big = BIG;

    // Initialize the board with empty cells
    resetBoard(bBig, big);

    // Set positions for fortresses (exits)
    bBig[0][0].itsCellType = FORTRESS;
    bBig[0][big-1].itsCellType = FORTRESS;
    bBig[big-1][0].itsCellType = FORTRESS;
    bBig[big-1][big-1].itsCellType = FORTRESS;

    // Set positions for the king and castle
    kingPos = { (big - 1) / 2, (big - 1) / 2 };
    bBig[kingPos.itsRow][kingPos.itsCol] = {CASTLE, KING};

    // Set positions for shields (defenders)
    Position shieldsPositionsBIG[] = {
            { kingPos.itsRow - 1, kingPos.itsCol },
            { kingPos.itsRow + 1, kingPos.itsCol },
            { kingPos.itsRow, kingPos.itsCol - 1 },
            { kingPos.itsRow, kingPos.itsCol + 1 },
            { kingPos.itsRow - 2, kingPos.itsCol },
            { kingPos.itsRow + 2, kingPos.itsCol },
            { kingPos.itsRow, kingPos.itsCol + 2 },
            { kingPos.itsRow, kingPos.itsCol - 2 },
            { kingPos.itsRow - 3, kingPos.itsCol },
            { kingPos.itsRow + 3, kingPos.itsCol },
            { kingPos.itsRow, kingPos.itsCol - 3 },
            { kingPos.itsRow, kingPos.itsCol + 3 },
    };

    for (const Position& pos : shieldsPositionsBIG) {
        bBig[pos.itsRow][pos.itsCol].itsPieceType = SHIELD;
    }

    // Set positions for swords (attackers)
    Position swordsPositionsBIG[] = {
            { kingPos.itsRow, 0 },
            { kingPos.itsRow - 1, 0 },
            { kingPos.itsRow - 2, 0 },
            { kingPos.itsRow + 1, 0 },
            { kingPos.itsRow + 2, 0 },
            { kingPos.itsRow, 1 },
            { kingPos.itsRow, big-1},
            { kingPos.itsRow - 1, big-1 },
            { kingPos.itsRow - 2, big-1 },
            { kingPos.itsRow + 1, big-1 },
            { kingPos.itsRow + 2, big-1 },
            { kingPos.itsRow, big-2 },
            { 0, kingPos.itsCol },
            { 0, kingPos.itsCol - 1 },
            { 0, kingPos.itsCol - 2 },
            { 0, kingPos.itsCol + 1 },
            { 0, kingPos.itsCol + 2 },
            { 1, kingPos.itsCol },
            { big-1, kingPos.itsCol },
            { big-1, kingPos.itsCol - 1 },
            { big-1, kingPos.itsCol - 2 },
            { big-1, kingPos.itsCol + 1 },
            { big-1, kingPos.itsCol + 2 },
            { big-2, kingPos.itsCol },
    };

    for (const Position& pos : swordsPositionsBIG) {
        bBig[pos.itsRow][pos.itsCol].itsPieceType = SWORD;
    }

    Cell yourBigBoard[BOARD_SIZE_MAX][BOARD_SIZE_MAX];
    initializeBoard(yourBigBoard, big);

    // Compare the generated board with the expected configuration
    for (int i = 0; i < big; ++i) {
        for (int j = 0; j < big; ++j) {
            if (yourBigBoard[i][j].itsCellType != bBig[i][j].itsCellType
                || yourBigBoard[i][j].itsPieceType != bBig[i][j].itsPieceType)
            {
                failed++;
            }
        }
    }
    if (failed) {
        cout << "FAIL ! \t: " << failed << " different cases" << endl;
        cout << endl << "\tActual " << endl;
        displayBoard(yourBigBoard, big);
        cout << endl << "\tExpected " << endl;
        displayBoard(bLittle, big);
        cout << endl;
    }
    else
    {
        cout << "PASS ! \t: " << endl;
        displayBoard(yourBigBoard, big);
        cout << endl;
        pass++;
    }

    // Display test results
    cout << "Totals: " << pass << " passed, " << failed << " failed" << endl;
    cout << "********* Finished testing of initializeBoard *********" << endl << endl;
}

/**
 * @brief Test function for the getPositionFromInput function.
 *
 * This function tests the getPositionFromInput function by providing various input strings and comparing the
 * returned positions with expected positions.
 */
void test_getPositionFromInput()
{
    cout << "********* Start testing of getPositionFromInput *********" << endl;
    int pass = 0; // Count of tests passed
    int failed = 0; // Count of tests failed

    // Input strings and their corresponding expected positions
    string inputStrings[8] = {"b6", "F9", "D11", "z345", " ", "1", "4e", "c5m"};
    Position expectedPositions[8] = {{1, 5}, {5, 8}, {3, 10}, {25,344}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}};

    for(int i=0 ; i<8 ; i++)
    {
        // Create an istringstream from the input string
        istringstream inputStream(inputStrings[i]);

        // Redirect cin (standard input) to the istringstream
        streambuf* originalCin = std::cin.rdbuf(); // Save the original cin stream
        cin.rdbuf(inputStream.rdbuf()); // Redirect cin to the istringstream

        // Get the position from input
        Position inputPosition = getPositionFromInput();
        if(inputPosition.itsCol == expectedPositions[i].itsCol
           && inputPosition.itsRow == expectedPositions[i].itsRow)
        {
            cout << "PASS \t: " << "Input : \"" << inputStrings[i] << "\" -> " <<
                 "Position : {" << inputPosition.itsRow << ", " << inputPosition.itsCol << "}" << endl << endl;
            pass++;
        }
        else
        {
            cout << "FAIL! \t: " << "Input : \"" << inputStrings[i] << "\" -> " <<
                 "\n\tActual Position : {" << inputPosition.itsRow << ", " << inputPosition.itsCol << "}" <<
                 "\n\tExpected Position : {" << expectedPositions[i].itsRow << ", " << expectedPositions[i].itsCol << "}" << endl << endl;
            failed++;
        }

        // Restore cin to its original state
        cin.rdbuf(originalCin);
    }

    // Display test results
    cout << "Totals: " << pass << " passed, " << failed << " failed" << endl;
    cout << "********* Finished testing of getPositionFromInput *********" << endl << endl;
}

/**
 * @brief Test function for the isValidPosition function.
 *
 * This function tests the isValidPosition function for different board sizes, valid positions, and invalid positions.
 * It counts the number of tests passed and failed and displays the results.
 */
void test_isValidPosition()
{
    cout << "********* Start testing of isValidPosition *********" << endl;
    int pass = 0; // Count of tests passed
    int failed = 0; // Count of tests failed

    BoardSize sizes[2] = {LITTLE, BIG}; // Board sizes to test

    for (BoardSize size : sizes)
    {
        if (size == LITTLE) cout << "LITTLE board :" << endl;
        else cout << "BIG board :" << endl;

        // Valid positions to test
        Position validPositionsToTest[] =
                {
                        {0, 0},
                        {0, size-1},
                        {size-1, 0},
                        {size-1, size-1},
                };

        // Invalid positions to test
        Position invalidPositionsToTest[] =
                {
                        {-1, 0},
                        {0, -1},
                        {size, 0},
                        {0, size},
                };

        // Test valid positions
        for(Position aPos : validPositionsToTest){
            if (isValidPosition(aPos, size))
            {
                cout << "PASS \t: " << aPos.itsRow << " " << aPos.itsCol << " is a valid position." << endl;
                pass++;
            }
            else
            {
                cout << "FAIL! \t: " << aPos.itsRow << " " << aPos.itsCol << "\n\tActual invalid position " <<
                     "\n\tExpected valid position" << endl;
                failed++;
            }
        }

        // Test invalid positions
        for(Position aPos : invalidPositionsToTest){
            if (!isValidPosition(aPos, size))
            {
                cout << "PASS \t: " << aPos.itsRow << " " << aPos.itsCol << " is an invalid position." << endl;
                pass++;
            }
            else
            {
                cout << "FAIL! \t: " << aPos.itsRow << " " << aPos.itsCol << "\n\tActual valid position " <<
                     "\n\tExpected invalid position" << endl;
                failed++;
            }
        }
    }

    // Display test results
    cout << "Totals: " << pass << " passed, " << failed << " failed" << endl;
    cout << "********* Finished testing of isValidPosition *********" << endl << endl;
}

/**
 * @brief Test function for the isEmptyCell function.
 *
 * This function tests the isEmptyCell function for different cell types and positions.
 * It counts the number of tests passed and failed and displays the results.
 */
void test_isEmptyCell()
{
    cout << "********* Start testing of isEmptyCell *********" << endl;
    int pass = 0; // Count of tests passed
    int failed = 0; // Count of tests failed

    Cell b[BOARD_SIZE_MAX][BOARD_SIZE_MAX]; // Game board
    resetBoard(b, BIG); // Reset the board to BIG size
    b[0][0] = {NORMAL, SWORD};
    b[0][1] = {NORMAL, SHIELD};
    b[0][2] = {NORMAL, KING};
    b[1][0] = {FORTRESS, KING};
    b[1][1] = {FORTRESS, NONE};
    b[2][0] = {CASTLE, KING};
    b[2][1] = {CASTLE, NONE};

    // Display the board for reference
    displayBoard(b, BIG);

    // Positions with non-empty cells to test
    Position nonEmptyPositionsToTest[] =
            {
                    {0, 0},
                    {0, 1},
                    {0, 2},
                    {1, 0},
                    {2, 0}
            };

    // Positions with empty cells to test
    Position emptyPositionsToTest[] =
            {
                    {0, 3},
                    {1, 1},
                    {2, 1}
            };

    // Expected results for each position
    string posToTest[] = {
            "A1 -> NORMAL / SWORD",
            "A2 -> NORMAL / SHIELD",
            "A3 -> NORMAL / KING",
            "B1 -> FORTRESS / KING",
            "C1 -> CASTLE / KING",
            "A4 -> NORMAL / NONE",
            "B2 -> FORTRESS / NONE",
            "C2 -> CASTLE / NONE"
    };

    int nTest = 0; // Test counter
    for(Position aPos : nonEmptyPositionsToTest){
        if (!isEmptyCell(b, aPos))
        {
            cout << "PASS \t: " << posToTest[nTest++] << " is not empty." << endl;
            pass++;
        }
        else
        {
            cout << "FAIL! \t: " << posToTest[nTest++] << "\n\tActual is empty " <<
                 "\n\tExpected is not empty" << endl;
            failed++;
        }
    }

    for(Position aPos : emptyPositionsToTest){
        if (isEmptyCell(b, aPos))
        {
            cout << "PASS \t: " << posToTest[nTest++] << " is empty." << endl;
            pass++;
        }
        else
        {
            cout << "FAIL! \t: " << posToTest[nTest++] << "\n\tActual is not empty " <<
                 "\n\tExpected is empty" << endl;
            failed++;
        }
    }

    // Display test results
    cout << "Totals: " << pass << " passed, " << failed << " failed" << endl;
    cout << "********* Finished testing of isEmptyCell *********" << endl << endl;
}

/**
 * @brief Test function for the isValidMovement function.
 *
 * This function tests the isValidMovement function for different types of moves
 * (ATTACK and DEFENSE) and various scenarios, including piece types and board cell types.
 * It counts the number of tests passed and failed and displays the results.
 */
void test_isValidMovement()
{
    cout << "********* Start testing of isValidMovement *********" << endl;
    int pass = 0; // Count of tests passed
    int failed = 0; // Count of tests failed

    BoardSize size = LITTLE;
    Cell b[BOARD_SIZE_MAX][BOARD_SIZE_MAX]; // Game board

    resetBoard(b,size);

    // Attack: Try to move the king - should fail
    b[1][1].itsPieceType = KING;
    displayBoard(b, size);
    if(!isValidMovement(ATTACK, b, {1, 1}, {2, 1}))
    {
        cout << "PASS \t: " << "Attack can't move the king in B2! " << endl << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: " << "\n\tActual Attack move the king ! " << "\n\texpected Attack can't move the king in B2 !" << endl;
        failed++;
    }

    // Attack: Try to move a shield - should fail
    b[2][2].itsPieceType = SHIELD;
    displayBoard(b, size);
    if(!isValidMovement(ATTACK, b, {2, 2}, {2, 3}))
    {
        cout << "PASS \t: " << "Attack can't move a shield in C3 !" << endl << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: " << "\n\tActual Attack move a shield ! " << "\n\texpected Attack can't move a shield in C3 !" << endl;
        failed++;
    }

    // Attack: Try to move a sword - should pass
    b[3][3].itsPieceType = SWORD;
    displayBoard(b, size);
    if(isValidMovement(ATTACK, b, {3, 3}, {2, 3}))
    {
        cout << "PASS \t: " << "Attack can move a sword in C3 to B3 !" << endl << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: " << "\n\tActual Attack can't move a sword ! " << "\n\texpected Attack can move a sword in C3 to B3 !" << endl;
        failed++;
    }

    // Attack: Try to move from an empty cell - should fail
    displayBoard(b, size);
    if(!isValidMovement(ATTACK, b, {4, 4}, {5, 4}))
    {
        cout << "PASS \t: " << "Attack can't move from an empty cell in E5 !" << endl << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: " << "\n\tActual Attack can move from an empty cell ! " << "\n\texpected Attack can't move from an empty cell in E5 !" << endl;
        failed++;
    }

    // Defense: Try to move the king - should pass
    b[1][1].itsPieceType = KING;
    displayBoard(b, size);
    if(isValidMovement(DEFENSE, b, {1, 1}, {2, 1}))
    {
        cout << "PASS \t: " << "Defense can move the king in B2 to B1 !" << endl << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: " << "\n\tActual Defense can't move the king ! " << "\n\texpected Defense can move the king in B2 to B1 !" << endl;
        failed++;
    }

    // Defense: Try to move a shield - should pass
    b[2][2].itsPieceType = SHIELD;
    displayBoard(b, size);
    if(isValidMovement(DEFENSE, b, {2, 2}, {2, 5}))
    {
        cout << "PASS \t: " << "Defense can move a shield in C3 to C6 !" << endl << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: " << "\n\tActual Defense can't move a shield ! " << "\n\texpected Defense can move a shield in C3 to C6 !" << endl;
        failed++;
    }

    // Defense: Try to move a sword - should fail
    b[3][3].itsPieceType = SWORD;
    displayBoard(b, size);
    if(!isValidMovement(DEFENSE, b, {3, 3}, {2, 3}))
    {
        cout << "PASS \t: " << "Defense can't move a sword in D4!" << endl << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: " << "\n\tActual Defense can move a sword ! " << "\n\texpected Defense can't move a sword in D4 !" << endl;
        failed++;
    }

    // Defense: Try to move from an empty cell - should fail
    displayBoard(b, size);
    if(!isValidMovement(DEFENSE, b, {9, 8}, {9, 4}))
    {
        cout << "PASS \t: " << "Defense can't move from an empty cell in J9 !" << endl << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: " << "\n\tActual Defense can move from an empty cell ! " << "\n\texpected Defense can't move from an empty cell in J9 !" << endl;
        failed++;
    }

    // Try to move a piece not in the same row or column - should fail
    displayBoard(b, size);
    if(!isValidMovement(DEFENSE, b, {2, 2}, {6, 1}))
    {
        cout << "PASS \t: " << "Movement from C3 to G2 is impossible if it's not the same row or the same column!" << endl << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: " << "\n\tActual move from C3 to G2 is possible ! " << "\n\texpected Movement from C3 to G2 is impossible if it's not the same row or the same column!" << endl;
        failed++;
    }

    // Piece in the way - SWORD attack
    resetBoard(b,size);
    b[3][3].itsPieceType = SWORD;
    b[5][3].itsPieceType = SHIELD;
    displayBoard(b, size);
    if(!isValidMovement(ATTACK, b, {3, 3}, {7, 3}))
    {
        cout << "PASS \t: " << "Movement D4 to H4 is impossible a piece is in the way!" << endl << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: " << "\n\tActual move is possible ! " << "\n\texpected Movement D4 to H4 is impossible a piece is in the way!" << endl;
        failed++;
    }

    // Piece in the way - SHIELD defense
    resetBoard(b,size);
    b[3][3].itsPieceType = SHIELD;
    b[3][6].itsPieceType = SWORD;
    displayBoard(b, size);
    if(!isValidMovement(DEFENSE, b, {3, 3}, {3, 7}))
    {
        cout << "PASS \t: " << "Movement D4 to D8 is impossible a piece is in the way!" << endl << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: " << "\n\tActual move is possible ! " << "\n\texpected Movement D4 to D8 is impossible a piece is in the way!" << endl;
        failed++;
    }

    // Piece in the way - KING attack
    resetBoard(b,size);
    b[4][7].itsPieceType = SWORD;
    b[4][2].itsPieceType = KING;
    displayBoard(b, size);
    if(!isValidMovement(ATTACK, b, {4, 7}, {4, 2}))
    {
        cout << "PASS \t: " << "Movement E8 to E3 is impossible a piece is in the way!" << endl << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: " << "\n\tActual move is possible ! " << "\n\texpected Movement E8 to E3 is impossible a piece is in the way!" << endl;
        failed++;
    }

    // Fortress in the way - ATTACK
    resetBoard(b,size);
    b[0][7].itsPieceType = SWORD;
    b[0][0].itsCellType = FORTRESS;
    displayBoard(b, size);
    if(!isValidMovement(ATTACK, b, {0, 7}, {0, 0}))
    {
        cout << "PASS \t: " << "Movement A8 to A1 is impossible to cross a fortress!" << endl << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: " << "\n\tActual move is possible ! " << "\n\texpected Movement A8 to A1 is impossible to cross a fortress!" << endl;
        failed++;
    }

    // Fortress in the way - DEFENSE
    resetBoard(b,size);
    b[size-1][7].itsPieceType = SHIELD;
    b[size-1][size-1].itsCellType = FORTRESS;
    displayBoard(b, size);
    if(!isValidMovement(DEFENSE, b, {size-1, 7}, {size-1, size-1}))
    {
        cout << "PASS \t: " << "Movement K8 to K11 is impossible to cross a fortress!" << endl << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: " << "\n\tActual move is possible ! " << "\n\texpected Movement K8 to K11 is impossible to cross a fortress!" << endl;
        failed++;
    }

    // Castle in the way - DEFENSE
    resetBoard(b,size);
    b[5][7].itsPieceType = SHIELD;
    b[5][5].itsCellType = CASTLE;
    displayBoard(b, size);
    if(!isValidMovement(DEFENSE, b, {5, 7}, {5, 2}))
    {
        cout << "PASS \t: " << "Movement F8 to F3 is impossible to cross the castle!" << endl << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: " << "\n\tActual move is possible ! " << "\n\texpected Movement F8 to F3 is impossible to cross the castle!" << endl;
        failed++;
    }

    // Castle in the way - ATTACK
    resetBoard(b,size);
    b[7][5].itsPieceType = SWORD;
    b[5][5].itsCellType = CASTLE;
    displayBoard(b, size);
    if(!isValidMovement(ATTACK, b, {7, 5}, {5, 5}))
    {
        cout << "PASS \t: " << "Movement H6 to F6 is impossible to cross the castle!" << endl << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: " << "\n\tActual move is possible ! " << "\n\texpected Movement H6 to F6 is impossible to cross the castle!" << endl;
        failed++;
    }

    // King finishing on a castle - DEFENSE
    resetBoard(b,size);
    b[7][5].itsPieceType = KING;
    b[5][5].itsCellType = CASTLE;
    displayBoard(b, size);
    if(isValidMovement(DEFENSE, b, {7, 5}, {5, 5}))
    {
        cout << "PASS \t: " << "Movement H6 to F6 is possible if it's the king!" << endl << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: " << "\n\tActual Movement H6 to F6 is impossible ! " << "\n\texpected Movement H6 to F6 is possible if it's the king" << endl;
        failed++;
    }

    // King finishing on a fortress - DEFENSE
    resetBoard(b,size);
    b[4][0].itsPieceType = KING;
    b[size-1][0].itsCellType = FORTRESS;
    displayBoard(b, size);
    if(isValidMovement(DEFENSE, b, {4, 0}, {size-1, 0}))
    {
        cout << "PASS \t: " << "Movement E1 to K1 is possible if it's the king!" << endl << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: " << "\n\tActual Movement E1 to K1 is impossible ! " << "\n\texpected Movement E1 to K1 is possible if it's the king" << endl;
        failed++;
    }

    cout << "Totals: " << pass << " passed, " << failed << " failed" << endl;
    cout << "********* Finished testing of isValidMovement *********" << endl << endl;
}

/**
 * @brief Test the movePiece function with different board sizes and piece types.
 *
 * This function tests the movePiece function by setting up various scenarios
 * with different board sizes (LITTLE and BIG) and different piece types (SWORD, SHIELD, KING).
 * It verifies whether pieces are correctly moved on the board.
 */
void test_movePiece()
{
    // Display the start of the movePiece testing.
    cout << "********* Start testing of movePiece *********" << endl;

    // Initialize pass and failed counters.
    int pass = 0;
    int failed = 0;

    // Create an array of board sizes to test (LITTLE and BIG).
    BoardSize sizes[2] = {LITTLE, BIG};

    // Iterate through the board sizes.
    for (BoardSize size : sizes)
    {
        // Display the current board size being tested.
        if (size == LITTLE)
            cout << "LITTLE board :" << endl;
        else
            cout << "BIG board :" << endl;

        // Create a 2D array representing the board.
        Cell b[BOARD_SIZE_MAX][BOARD_SIZE_MAX];

        // Initialize the board.
        resetBoard(b, size);

        // Place a fortress at the upper-right corner and a castle at the lower-left corner.
        b[0][size - 1].itsCellType = FORTRESS;
        b[size - 1][0].itsCellType = CASTLE;

        // Define start and end positions for piece movements.
        Position pos[5] = {{0, 0}, {0, size - 1}, {size - 1, size - 1}, {size - 1, 0}, {0, 0}};

        // Define piece types to test: SWORD, SHIELD, and KING.
        PieceType piecesTypes[3] = {SWORD, SHIELD, KING};

        // Iterate through piece types.
        for (PieceType itsPieceType : piecesTypes)
        {
            // Display the current piece type being tested.
            if (itsPieceType == SWORD)
                cout << "SWORD movements :" << endl;
            else if (itsPieceType == SHIELD)
                cout << "SHIELD movements :" << endl;
            else
                cout << "KING movements :" << endl;

            // Place the piece on the board.
            b[0][0].itsPieceType = itsPieceType;
            displayBoard(b, size);

            // Iterate through possible movements (from 0 to 3).
            for (int i = 0; i < 4; ++i)
            {
                // Perform the piece movement.
                movePiece(b, pos[i], pos[i + 1]);
                displayBoard(b, size);

                // Check if the piece has been moved correctly.
                if (b[pos[i].itsRow][pos[i].itsCol].itsPieceType == NONE &&
                    b[pos[i + 1].itsRow][pos[i + 1].itsCol].itsPieceType == itsPieceType)
                {
                    // Display a pass message.
                    cout << "PASS \t: " << (char)(pos[i].itsRow + 'A') << pos[i].itsCol + 1 << " to "
                         << (char)(pos[i + 1].itsRow + 'A') << pos[i + 1].itsCol + 1 << endl << endl;
                    pass++;
                }
                else
                {
                    // Display a fail message.
                    cout << "FAIL! \t: " << (char)(pos[i].itsRow + 'A') << pos[i].itsCol + 1 << " to "
                         << (char)(pos[i + 1].itsRow + 'A') << pos[i + 1].itsCol + 1 << endl << endl;
                    failed++;
                }
            }
        }
    }

    // Display the total pass and failed counts.
    cout << "Totals: " << pass << " passed, " << failed << " failed" << endl;

    // Display the end of the movePiece testing.
    cout << "********* Finished testing of movePiece *********" << endl << endl;
}