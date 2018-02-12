/*
 * HW : HW02
 * File:   connectFour.h
 * Author: Sema Köse
 * Number: 141044002
 * 
 * This is a Connect-4 game.
 *
 * This game takes an input from user as column and make the move to the bottom line in that column.
 * 
 * The game has 2 mod : playerVSplayer and computerVSplayer
 *
 * User represented as 'X' and computer or 2nd user represented as 'O'
 */

#ifndef CONNECTFOUR_H
#define CONNECTFOUR_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

const int getTheBoardSize(); // gets the board size from user
void fillTheBoardWithDots(int boardSize, char** theBoard); // initializes the board with '.'
void drawTheBoard(int boardSize, char** theBoard); // prints the current board to the screen
char** createTheBoard(const int boardSize); //creates the board with given nxn size using malloc
int getTheGamingMode(); // gets the gaming mode (player vs player or computer vs player) from user
void displayTheScore(int player_1, int player_2_or_computer, int mode); // displays who's winning
char** getInputFromPlayer(char** theBoard, int boardSize, std::string& input, char* column, int* row); //gets the column as an input and finds an empty row in that column
std::string getColumn(int boardSize, int* inputType); // gets the column from user
int getRow(char** theBoard, int boardSize, char column); // finds an empty row
char** player(char** theBoard, const int theBoardSize, int* rowInput, int* columnInput, char playerSign); // user acts
int playerVersusPlayer(char** theBoard, const int theBoardSize, int gamingMode); // player vs player gaming mode
int isItAScore(char** theBoard, int row, int column, char player, const int boardSize); // calculates the score
int bestOdds(char**theBoard, int boardSize); // calculates all odds for computer and returns the best of them
bool computer(char** theBoard, const int theBoardSize, int* rowInput, int* columnInput, char playerSign); // computer acts
int computerVersusPlayer(char** theBoard, const int theBoardSize, int gamingMode); // computer vs player gaming mode
int* calculateCounts(char** theBoard, int row, int column, char player, const int boardSize); // a helper function for bestOdds dunction
bool isTheBoardAvailable(char** theBoard, int theBoardSize); // calculates if there is any empty cell on the board

const int countArraySize = 4;
static int gamingModeGlob;
static int boardSizeHelper;
static int loaded;
//HW02

bool checkIfItsAFileCommand(const std::string command);
char** fileOperations(const std::string& input, char** theBoard, int& boardSize);


#endif /* CONNECTFOUR_H */

