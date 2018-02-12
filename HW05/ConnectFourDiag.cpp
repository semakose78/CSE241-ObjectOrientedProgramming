//
// Sema Köse
// 141044002
// HW05
//

#include "ConnectFourDiag.h"
using namespace ConnectFour;

int ConnectFourDiag::isItAScore(int row, int column, char player){
    int count = 0;
    int score = 0;
    int sign = 0;
    int i=row;

    if(player == 'x')
        sign = 1;
    if(player == 'o')
        sign = 2;

    //diagonally right up to left bottom
    count = 1;
    i = column;
    int j = row;

    while(i<width && j>0 && (gameBoard[j][i].getSituation() == sign)){
        ++i;
        --j;
        //cout<<count<<"    hereeee"<<endl;
        //cout<<i<<"    hereeee"<<endl;
        //cout<<j<<"    hereeee"<<endl;

        //exit(1);
    }
    --i;
    ++j;
    while(i>0 && j<height && (gameBoard[j][i].getSituation() == sign)){

        --i;
        ++j;
        ++count;

    }
    if(count>=4)
        ++score;


    //diagonally left up to right bottom
    count = 1;
    i = column;
    j = row;

    while(i>0 && j>0 && (gameBoard[j-1][i-1].getSituation() == sign)){
        --i;
        --j;
    }
    ++i;
    ++j;
    while(i<width && j<height && (gameBoard[j][i].getSituation() == sign)){
        ++i;
        ++j;
        ++count;
        //cout<<count<<"    hereeee"<<endl;

    }
    if(count>=4)
        ++score;


    return score;
}
