//
// Sema Köse
// 141044002
// HW05
//

#include "ConnectFourPlusUndo.h"
using namespace std;
using namespace ConnectFour;

int ConnectFourPlusUndo::isItAScore(int row, int column, char player){
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

void ConnectFourPlusUndo::play(int* rowInput, int* columnInput, char playerSign){ // user acts
    string input = "\0";
    char column = '\0';
    int row = 0;
    string player;

    if(playerSign == 'o')
        player = "P2";
    else
        player = "P1";

    getInputFromPlayer(player, input, &column, &row); // get a letter for column and row

    *rowInput = row;

    if(input.compare("SAVE") == 0){
        cout<<"Game saved successfully!"<<endl;
        play(rowInput, columnInput, playerSign);
    }else if(input.compare("LOAD") == 0){
        cout<<"Game loaded successfully!"<<endl;
        //player(newBoard, boardSizeHelper, rowInput, columnInput, playerSign);
    }else if(input.compare("UNDO") == 0){
        cout<<"UNDO 1 move!"<<endl;
        int c = movesCols.at(movesCols.size()-1);
        int r = movesRows.at(movesRows.size()-1);
        gameBoard[r][c].setSituation(0);

        //player(newBoard, boardSizeHelper, rowInput, columnInput, playerSign);
    }else if(((int)column) < 97){ //if it's a lowercase letter
        *columnInput = (int)column-65; // 65 is decimal value for 'a' in ASCII table
        movesCols.push_back(*columnInput);
        movesRows.push_back(row);
        if(gameBoard[row][((int)column)-65].getSituation() == 0) //if the move is legal
        {
            if(playerSign == 'o')
                gameBoard[row][((int)column)-65].setSituation(2); //put the sign to that cell
            else
                gameBoard[row][((int)column)-65].setSituation(1); //put the sign to that cell
        }

        else{
            cout<<"This move is not legal! Please try another move"<<endl;
            play(rowInput, columnInput, playerSign);
        }
        ++numberOfLivingCells;
    } else if(((int)column) >= 97){ //if it's a uppercase letter
        *columnInput = (int)column-97; // 97 is decimal value for 'A' in ASCII table
        if(gameBoard[row][((int)column)-97].getSituation() == 0) //if the move is legal
        {
            if(playerSign == 'o')
                gameBoard[row][((int)column)-97].setSituation(2); //put the sign to that cell
            else
                gameBoard[row][((int)column)-97].setSituation(1); //put the sign to that cell
        }

        else{
            cout<<"This move is not legal! Please try another move"<<endl;
            play(rowInput, columnInput, playerSign);

        }
        ++numberOfLivingCells;
    }
}

bool ConnectFourPlusUndo::play(){ // computer acts
    int row = 0;
    int column = 0;
    int index = 0;
    index = bestOdds(); // calculate the odds take the best as column
    playHelper(&row, &index, 'o');
    return true;
}
