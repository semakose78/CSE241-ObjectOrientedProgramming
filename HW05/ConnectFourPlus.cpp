//
// Sema Köse
// 141044002
// HW05
//

#include "ConnectFourPlus.h"
using namespace ConnectFour;

int ConnectFourPlus::isItAScore(int row, int column, char player){
    int count = 0;
    int score = 0;
    int sign = 0;

    if(player == 'x')
        sign = 1;
    if(player == 'o')
        sign = 2;

    //vertical
    int i=row;

    while(i>0 && gameBoard[i-1][column].getSituation() == sign){
        --i;
    }
    while(i<height && gameBoard[i][column].getSituation() == sign){
        ++i;
        ++count;
    }
    if(count>=4)
        ++score;

    //horizontal
    count = 0;
    i = column;

    while(i>0 && gameBoard[row][i-1].getSituation() == sign){
        --i;
    }
    while(i<width && gameBoard[row][i].getSituation() == sign){
        ++i;
        ++count;
    }
    if(count>=4)
        ++score;

    return score;
}
