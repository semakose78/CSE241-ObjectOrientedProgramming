/*
 * HW : HW02
 * File:   connectFour.cpp
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
using namespace std;


const int getTheBoardSize(){ // gets the board size from user

    int widthInput = 0;

    cout << "Please enter the board size that you want to play as '2n' between the 4 and the 20 for '2nx2n' game board." <<endl;
    cout<<endl;
    cin >> widthInput;

    if((widthInput != 0) && (widthInput >= 4) && ((widthInput%2) == 0) && (widthInput <= 20)){
        return widthInput; // return the size
    }
    else{
        cerr<<"The input is not valid!"<<endl; //if the input is not valid, ask again recursively
        cin.clear();
        cin.ignore(1000, '\n');
        getTheBoardSize();
    }
}

char** createTheBoard(const int boardSize = 8){ //creates the board with given nxn size using malloc
    char **boardArray;
    if(loaded==1)
        cout<<"The board size is : "<<boardSize<<endl;
    boardArray = (char**)malloc(boardSize*sizeof(char*));
    for(int i = 0; i< boardSize; i++){
        boardArray[i] = (char*)malloc(sizeof(char));
    }

    fillTheBoardWithDots(boardSize, boardArray); //fill the cells with '.'
    if(!loaded)
        drawTheBoard(boardSize, boardArray); //and display it
    return boardArray; // return the array
}

void fillTheBoardWithDots(int boardSize, char** theBoard){ // initializes the board with '.'
    for(int i = 0; i< boardSize; i++){
        for(int j = 0; j< boardSize; j++){
            theBoard[i][j] = '.';
        }
    }
}

void drawTheBoard(int boardSize, char** theBoard){ // prints the current board to the screen
    int t = 1;
    if(loaded == 1)
        loaded = 0;
    for(int k=65; k<(65+boardSize); k++) //print the column letters first
        cout<<(char)k;
    cout<<endl;
    for(int i = 0; i< boardSize; i++){
        //if(t<10)
        //    cout<<t<<' ';
        //else
        //    cout<<t;
        for(int j = 0; j< boardSize; j++){
            cout << theBoard[i][j];
        }
        cout<<endl;
        ++t;
    }
    cout<<endl;
}

int getTheGamingMode(){ // gets the gaming mode (player vs player or computer vs player) from user

    int mode = 0;
    char modeAsChar = '\0';
    cout<<endl;
    cout << "Please enter the letter near by the gaming mode you wanna play:" <<endl;
    cout << "(P) 2-Player" <<endl;
    cout << "(C) User vs Computer" <<endl;
    cout<<endl;
    cin >> modeAsChar;
    
    if(modeAsChar == 'P')
        mode = 1;
    else if(modeAsChar == 'C')
        mode = 2;
    
    if(mode==1 || mode==2)
        return mode; // return the mode
    else{
        cerr << "Please enter a valid mode" << endl; //if input is not valid ask again recursively
        cin.clear();
        cin.ignore(1000, '\n');
        getTheGamingMode();
    }
}

void displayTheScore(int player_1 = 0, int player_2_or_computer = 0, int mode = 1){ // displays who's winning
    if(mode == 1){
        cout<<"Player 1 : "<<player_1<<endl;
        cout<<"Player 2 : "<<player_2_or_computer<<endl;
    }else if(mode == 2){
        cout<<"Player 1 : "<<player_1<<endl;
        cout<<"Player 2 : "<<player_2_or_computer<<endl;
    }
    cout<<endl;
} //display the score as 0-0 initially

/*void getInputFromPlayer(char** thaBoard, int boardSize, char* column, int* row){ //gets the column as an input and finds an empty row in that column
    *column = getColumn(boardSize); //get the column
    *row = getRow(thaBoard, boardSize, *column); //calculate the row
    if(*row<0){
        cout<<endl<<"There is no room for that move in this column!"<<endl; //check if there is any cells for move
        getInputFromPlayer(thaBoard, boardSize, column, row);
    }

}*/

char** getInputFromPlayer(char** thaBoard, int boardSize, string& input, char* column, int* row){ //gets the column as an input and finds an empty row in that column
    int inputType = 0;
    char** newBoard;
    input = getColumn(boardSize, &inputType); //get the column
    //cout<<input<<endl;
    if(inputType == 0){
        *column = input[0];
        *row = getRow(thaBoard, boardSize, *column); //calculate the row
        if(*row<0){
            cout<<endl<<"There is no room for that move in this column!"<<endl; //check if there is any cells for move
            getInputFromPlayer(thaBoard, boardSize, input, column, row);
        }
    }
    else{
        //cout<<"here"<<endl;
        newBoard = fileOperations(input, thaBoard, boardSize);
    }
    return newBoard;
}

string getColumn(int boardSize, int* inputType){ // gets the column from user
    string input = "\0";
    char column = '\0';
    cout << "Please enter the column letter for your move: " <<endl;
    cin >> input;
    if(!checkIfItsAFileCommand(input)){

        *inputType = 0;
        column = input[0];
        if(((int)column)<65 || (((int)column)>(64+boardSize) && ((int)column)<97) //check if the move is valid
           || ((int)column)>(96+boardSize)){

            cerr << "The move is not valid!" <<endl;
            cin.clear();
            cin.ignore(1000, '\n');
            getColumn(boardSize, inputType);
        }
        return input; // return column as letter
    }
    else{
        *inputType = 1;
        return input;
    }
}

int getRow(char** theBoard, int boardSize, char column){ // finds an empty row in a column
    int row = 0;
    int i = 0;
    for(i=(boardSize-1); i>=0; --i){
        if((int)(column)<97){
            if(theBoard[i][(int)(column-65)] == '.')
                break;
        }
        else if((int)(column)>=97){
            if(theBoard[i][(int)(column-97)] == '.')
                break;
        }
    }
    row = i;
    return row; // return the row for move
}

char** player(char** theBoard, const int theBoardSize, int* rowInput, int* columnInput, char playerSign){ // user acts
    string input = "\0";
    char column = '\0';
    int row = 0;
    char** newBoard;

    newBoard = getInputFromPlayer(theBoard, theBoardSize, input, &column, &row); // get a letter for column and row

    *rowInput = row;

    if(input.compare("SAVE") == 0){
        cout<<"Game saved successfully!"<<endl;
        player(theBoard, theBoardSize, rowInput, columnInput, playerSign);
    }else if(input.compare("LOAD") == 0){
        cout<<"Game loaded successfully!"<<endl;
        //player(newBoard, boardSizeHelper, rowInput, columnInput, playerSign);
    }else if(((int)column) < 97){ //if it's a lowercase letter
        *columnInput = (int)column-65; // 65 is decimal value for 'a' in ASCII table
        if(theBoard[row][((int)column)-65] == '.') //if the move is legal
            theBoard[row][((int)column)-65] = playerSign; //put the sign to that cell
        else{
            cout<<"This move is not legal! Please try another move"<<endl;
            player(theBoard, theBoardSize, rowInput, columnInput, playerSign);
        }
    } else if(((int)column) >= 97){ //if it's a uppercase letter
        *columnInput = (int)column-97; // 97 is decimal value for 'A' in ASCII table
        if(theBoard[row][((int)column)-97] == '.') //if the move is legal
            theBoard[row][((int)column)-97] = playerSign; //put the sign to that cell
        else{
            cout<<"This move is not legal! Please try another move"<<endl;
            player(theBoard, theBoardSize, rowInput, columnInput, playerSign);

        }
    }
    return newBoard;
}

int playerVersusPlayer(char** theBoard, const int theBoardSize, int gamingMode){ // player vs player gaming mode

    int row = 0;
    int column = 0;
    int score_1 = 0, score_2 = 0;
    char** newBoard;
    gamingModeGlob = gamingMode;
    cout<<endl<<"Turn : Player 1"<<endl; // first player
    newBoard = player(theBoard, theBoardSize, &row, &column, 'x'); // make the move
    if(gamingModeGlob == 1 && !loaded){
        drawTheBoard(theBoardSize, theBoard); //draw the board
        score_1 = isItAScore(theBoard, row, column, 'x', theBoardSize); // is it winning?
        displayTheScore(score_1, score_2, gamingMode); // display the score
        if(score_1 >= 1){ // if it's winning
            cout<<"Game Over! Player 1 Won!!"<<endl;
            drawTheBoard(theBoardSize, theBoard); // draw the winning table
            displayTheScore(score_1, score_2, gamingMode); // display the winning score
            return 0; //end
        }
        cout<<endl<<"Turn : Player 2"<<endl; // second player
        player(theBoard, theBoardSize, &row, &column, 'o'); // make the move
        drawTheBoard(theBoardSize, theBoard); //draw the board
        score_2 = isItAScore(theBoard, row, column, 'o', theBoardSize); // is it winning?
        displayTheScore(score_1, score_2, gamingMode); // display the score
        if(score_2 >= 1){ // if it's winning
            cout<<"Game Over! Player 2 Won!!"<<endl;
            drawTheBoard(theBoardSize, theBoard); // draw the winning table
            displayTheScore(score_1, score_2, gamingMode); // display the winning score
            return 1; //end
        }
        if(isTheBoardAvailable(theBoard, theBoardSize)) // if the board is available
            playerVersusPlayer(theBoard, theBoardSize, gamingMode); // turn for another move
        else{  // if the board is not available
            cout<<"Game Over! The Board Is Filled!"<<endl;
            drawTheBoard(theBoardSize, theBoard); // draw the last version of the table
            displayTheScore(score_1, score_2, gamingMode); // draw the last version of the score
            return 2; //end
        }
    }else if(gamingModeGlob == 1 && loaded){

        drawTheBoard(boardSizeHelper, newBoard); //draw the board
        playerVersusPlayer(newBoard, boardSizeHelper, gamingMode);
    }
    else{
        drawTheBoard(boardSizeHelper, newBoard); //draw the board
        computerVersusPlayer(newBoard, boardSizeHelper, gamingModeGlob);
    }
}

int isItAScore(char** theBoard, int row, int column, char player, const int boardSize){ // calculates the score
    int count = 0;
    int score = 0;

    //vertical
    int i=row;

    while(i>0 && theBoard[i-1][column] == player){
        --i;
    }
    while(i<boardSize && theBoard[i][column] == player){
        ++i;
        ++count;
    }
    if(count>=4)
        ++score;

    //horizontal
    count = 0;
    i = column;

    while(i>0 && theBoard[row][i-1] == player){
        --i;
    }
    while(i<boardSize && theBoard[row][i] == player){
        ++i;
        ++count;
    }
    if(count>=4)
        ++score;

    //diagonally right up to letf bottom
    count = 0;
    i = column;
    int j = row;

    while(i<boardSize && j>0 && theBoard[j-1][i+1] == player){
        ++i;
        --j;
    }
    while(i>0 && j<boardSize && theBoard[j][i] == player){
        --i;
        ++j;
        ++count;
    }
    if(count>=4)
        ++score;

    //diagonally left up to right bottom
    count = 0;
    i = column;
    j = row;

    while(i>0 && j>0 && theBoard[j-1][i-1] == player){
        --i;
        --j;
    }
    while(i<boardSize && j<boardSize && theBoard[j][i] == player){
        ++i;
        ++j;
        ++count;
    }
    if(count>=4)
        ++score;

    return score;
}

int bestOdds(char** theBoard, int boardSize){  // calculates all odds for computer and returns the best of them
    char** newBoard;
    int row = 0;
    int computerOddsArray[boardSize];
    int playerOddsArray[boardSize];
    int oddIndexForPlayer = 0;
    int oddIndexForComputer = 0;
    int *checkCountArray;
    int oddComp = 0;
    int oddPly = 0;
    int cntComp = 0;
    int cntPly = 0;
    int min = 0;

    // create the copy board
    newBoard = (char**)malloc(boardSize*sizeof(char*)); 
    for(int i = 0; i< boardSize; i++){
        newBoard[i] = (char*)malloc(sizeof(char));
    }

    // fill the copy board with the original table values
    for(int i=0; i<boardSize; ++i){
        for(int j=0; j<boardSize; ++j)
            newBoard[i][j] = theBoard[i][j];
    }

    //begin from the first column
    for(int k=0; k<boardSize; ++k){
        row = getRow(newBoard, boardSize, k+65); //get the first available row
        min = k;
        if(row>-1){
            computer(newBoard, boardSize, &row, &k, 'o'); //make the move
            oddComp = isItAScore(newBoard, row, k, 'o', boardSize); //if it's a score
            if(oddComp >= 1)
                return k; //play for that move, so return that column for play
            else{ //if it's not score
                checkCountArray = calculateCounts(newBoard, row, k, 'o', boardSize); //calculate how many o's are there for all dimentions and fill an array
                for(int p = 0; p<(countArraySize-1); ++p){ // calculate the biggest value in the countsArray
                    int temp1 = 0;
                    int temp2 = 0;
                    temp1 = checkCountArray[p];
                    temp2 = checkCountArray[p+1];
                    if(temp1 > temp2)
                        cntComp = temp1;
                    else if(temp2>cntComp)
                        cntComp = temp2;
                }
                for(int t=0; t<boardSize; ++t){ //start from the first column
                    row = getRow(newBoard, boardSize, t+65); //calculate the first available cell in that column
                    if(row>-1){
                        computer(newBoard, boardSize, &row, &t, 'x'); //play for the foe
                        oddPly = isItAScore(newBoard, row, t, 'x', boardSize); // is it a score?
                        if(oddPly >= 1){ //if it's a score
                            playerOddsArray[t] = 1; //put 1 to score array for foe
                        }else{
                            playerOddsArray[t] = 0; //else put 0 to score array for foe
                            checkCountArray = calculateCounts(newBoard, row, t, 'x', boardSize); //calculate how many x's are there for all dimentions and fill an array
                            for(int r = 0; r<(countArraySize-1); ++r){ // calculate the biggest value in the countsArray
                                int temp1 = 0;
                                int temp2 = 0;
                                temp1 = checkCountArray[r];
                                temp2 = checkCountArray[r+1];
                                if(temp1 > temp2)
                                    cntPly = temp1;
                                else
                                    cntPly = temp2;
                            }
                            if(cntPly==4) //return the best move for computer
                                return t;
                        }
                    }

                    computer(newBoard, boardSize, &row, &t, '.');
                }
            }
            if(cntComp>cntPly) //return the best move for computer
                return k;
        }
        computer(newBoard, boardSize, &row, &k, '.');
    }
    for(int f = 0; f<boardSize; ++f){
        char *ptr = newBoard[f];
        free(ptr);
    }
    return min;
}

bool computer(char** theBoard, const int theBoardSize, int* rowInput, int* columnInput, char playerSign){ // computer acts

    //if(theBoard[*rowInput][*columnInput] == '.') // if the cell is available
    if(*rowInput > -1)
        theBoard[*rowInput][*columnInput] = playerSign; // put the sign to that cell
}

int computerVersusPlayer(char** theBoard, const int theBoardSize, int gamingMode){ // computer vs player gaming mode

    int row = 0;
    int column = 0;
    int index = 0;
    int score_1 = 0, score_2 = 0;
    gamingModeGlob = gamingMode;
    char** newBoard;
    cout<<endl<<"Turn : Player 1"<<endl; // first player
    newBoard = player(theBoard, theBoardSize, &row, &column, 'x'); // make the move
    if(gamingModeGlob == 2 && !loaded){
        drawTheBoard(theBoardSize, theBoard); //draw the board
        score_1 = isItAScore(theBoard, row, column, 'x', theBoardSize); // is it winning?
        displayTheScore(score_1, score_2, gamingMode); // display the score
        if(score_1 >= 1){ // if it's winning
            cout<<"Game Over! Player Won!!"<<endl;
            drawTheBoard(theBoardSize, theBoard); // draw the winning table
            displayTheScore(score_1, score_2, gamingMode); // display the winning score
            return 0; //end
        }
        cout<<endl<<"Turn : Computer"<<endl; // computer
        index = bestOdds(theBoard, theBoardSize); // calculate the odds take the best as column
        row = getRow(theBoard, theBoardSize, index+65);  // calculate the row for the best column odd
        computer(theBoard, theBoardSize, &row, &index, 'o'); // make the move
        drawTheBoard(theBoardSize, theBoard); //draw the board
        score_2 = isItAScore(theBoard, row, index, 'o', theBoardSize); // is it winning?
        displayTheScore(score_1, score_2, gamingMode); // display the score
        if(score_2 >= 1){ // if it's winning
            cout<<"Game Over! Computer Won!!"<<endl;
            drawTheBoard(theBoardSize, theBoard); // draw the winning table
            displayTheScore(score_1, score_2, gamingMode); // display the winning score
            return 0; //end
        }
        if(isTheBoardAvailable(theBoard, theBoardSize)) // if the board is available
            computerVersusPlayer(theBoard, theBoardSize, gamingMode); // turn for another move
        else{
            cout<<"Game Over! The Board Is Filled!"<<endl;
            drawTheBoard(theBoardSize, theBoard); // draw the last version of the table
            displayTheScore(score_1, score_2, gamingMode); // draw the last version of the score
            return 2; //end
        }
    }else if(gamingModeGlob == 2 && loaded){
        loaded = 0;
        drawTheBoard(theBoardSize, theBoard); //draw the board
        computerVersusPlayer(theBoard, theBoardSize, gamingMode);
    }else{
        drawTheBoard(boardSizeHelper, newBoard); //draw the board
        playerVersusPlayer(newBoard, boardSizeHelper, gamingModeGlob);
    }
}

// calculateCounts is same as the isItAScore function but returns the number of the same letter repeatedly for all odds (like "ooo" - how many o?)
int* calculateCounts(char** theBoard, int row, int column, char player, const int boardSize){ // a helper function for bestOdds dunction

    int count = 0;
    int score = 0;
    static int countArray[countArraySize];
    //vertical
    int i=row;

    while(i>0 && theBoard[i-1][column] == player){
        --i;
    }
    ++i;
    while(i<boardSize && theBoard[i][column] == player){
        ++i;
        ++count;
    }
    countArray[1] = count;
    if(count>=4)
        ++score;

    //horizontal
    count = 0;
    i = column;

    while(i>0 && theBoard[row][i-1] == player){
        --i;
    }
    while(i<boardSize && theBoard[row][i] == player){
        ++i;
        ++count;
    }
    countArray[2] = count;
    if(count>=4)
        ++score;

    //diagonally right up to letf bottom
    count = 0;
    i = column;
    int j = row;

    while(i<boardSize && j>0 && theBoard[j][i] == player){
        ++i;
        --j;
    }
    while(i>0 && j<boardSize && theBoard[j][i] == player){
        --i;
        ++j;
        ++count;
    }
    countArray[3] = count;
    if(count>=4)
        ++score;

    //diagonally left up to right bottom
    count = 0;
    i = column;
    j = row;

    while(i>0 && j>0 && theBoard[j][i] == player){
        --i;
        --j;
    }
    while(i<boardSize && j<boardSize && theBoard[j][i] == player){
        ++i;
        ++j;
        ++count;
    }
    countArray[4] = count;
    if(count>=4)
        ++score;

    return countArray;
}

bool isTheBoardAvailable(char** theBoard, int theBoardSize){ // calculates if there is any empty cell on the board
    bool available = false;
    for(int i= 0; i<theBoardSize; ++i){
        for(int j = 0; j<theBoardSize; ++j){
            if(theBoard[i][j] == '.'){ // if there is any empty cell return true
                available = true;
                break;
            }
        }
        if(available == true){
            break;
        }
    }

    return available; // return if there is an empty cell or not
}

bool checkIfItsAFileCommand(const string command){

    //cout<<command<<endl;

    if(command == "LOAD" || command == "SAVE")
        return true;
    else
        return false;
}

char** fileOperations(const string& input, char** theBoard, int& boardSize){
    ofstream outFile;
    ifstream inFile;
    string filename;
    char ch = '\0';
    auto gamingModeCodeForInput = boardSize; //auto statement
    decltype(gamingModeCodeForInput) boardSizeForInput; //decltype statement
    cin >> filename;
    char **newBoard;

    if(input.compare("SAVE")==0){
        //cout<<"save file detected"<<endl;
        outFile.open(filename);
        if(outFile){
            outFile << boardSize << endl;
            outFile << gamingModeGlob << endl;
            for(int i=0; i<boardSize; ++i){
                for(int j=0; j<boardSize; ++j){
                    outFile << theBoard[i][j];
                }
                outFile << endl;
            }
        }else{
            cerr<<"File couldn't opened for SAVE"<<endl;
        }

    }
    else if(input.compare("LOAD")==0){
        //cout<<"load file detected"<<endl;
        loaded = 1;
        inFile.open(filename);
        if(inFile){
            inFile >> boardSizeForInput;
            boardSizeHelper = boardSizeForInput;
            newBoard = createTheBoard(boardSizeForInput);
            //inFile >> ch;
            inFile >> gamingModeCodeForInput;
            gamingModeGlob = gamingModeCodeForInput;
            if(gamingModeGlob==1)
                cout<<"The gaming mode is Player vs Player"<<endl;
            else if(gamingModeGlob==2)
                cout<<"The gaming mode is Player vs Computer"<<endl;
            //inFile >> ch;
            for(int i=0; i<boardSizeForInput; ++i){
                for(int j=0; j<boardSizeForInput; ++j){
                    inFile >> ch;
                    newBoard[i][j] = ch;
                }
                //inFile >> ch;
            }
            //open the file and init the board and print to the screen
        }else{
            cerr<<"File couldn't opened for LOAD"<<endl;
        }

    }
    outFile.close();
    inFile.close();
    return newBoard;
}



