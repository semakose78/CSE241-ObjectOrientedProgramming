//
// Sema Köse
// 141044002
// HW05
//

#include <iostream>

#include "ConnectFourAbstract.h"
#include "ConnectFourPlus.h"
#include "ConnectFourDiag.h"
#include "ConnectFourPlusUndo.h"
using namespace ConnectFour;

int main() {
    char type;
    cin>>type;

	if(type=='P'){
        ConnectFourPlus game;
        game.setType(type);
        game.setTheBoardSize();
        game.setTheGamingMode();
        game.createTheBoard();
        game.fillTheBoardWithZeros();
        game.playGame();
    }else if(type=='D'){
        ConnectFourDiag game;
        game.setType(type);
        game.setTheBoardSize();
        game.setTheGamingMode();
        game.createTheBoard();
        game.fillTheBoardWithZeros();
        game.playGame();
    }else if(type=='U'){
        ConnectFourPlusUndo game;
        game.setType(type);
        game.setTheBoardSize();
        game.setTheGamingMode();
        game.createTheBoard();
        game.fillTheBoardWithZeros();
        game.playGame();
    }


    return 0;
}
