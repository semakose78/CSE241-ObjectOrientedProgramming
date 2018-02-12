/*
 * HW : HW01
 * File:   main.cpp
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

#include "connectFour.h"

int main(int argc, char** argv) {

    int boardSize = 0;
    int gamingMode = 0;
    char **boardArray = NULL;
    int result = 0;

    boardSize = getTheBoardSize();
    gamingMode = getTheGamingMode();
    boardArray = createTheBoard(boardSize);
    displayTheScore(0, 0, gamingMode);

    if(gamingMode == 1){
        playerVersusPlayer(boardArray, boardSize, gamingMode);
    }else if(gamingMode == 2){
        computerVersusPlayer(boardArray, boardSize, gamingMode);
    }
    for(int f = 0; f<boardSize; ++f){
        char *ptr = boardArray[f];
        free(ptr);
    }
    return 0;
}