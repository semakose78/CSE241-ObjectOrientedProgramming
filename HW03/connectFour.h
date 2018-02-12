//
// Sema Köse
// 141044002
// HW03
// connectFour.h

#ifndef CONNECTFOUR_H
#define CONNECTFOUR_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class ConnectFour {
public:
    ConnectFour();
    ConnectFour(int wOrH);
    ConnectFour(int w, int h);
    int getWidth() const {return width;}; //inline function returns the current width
    int getHeight() const {return height;}; //inline function returns the current height
    int getTheGamingMode() const {return playerOrComputer;};
    char getSingleOrMulti() const {return singleOrMulti;};
    static int getNumberOfLivingCells() {return numberOfLivingCells;};
    void setObject(int obj){object = obj;};
    static int getObject(){return object;};
    void setWidth(int width);
    void setHeight(int height);
    void setSingleOrMulti();
    int setTheBoardSize();
    void setTheGamingMode();
    void setGameNumber(int num){gameNumber = num;};
    void fillTheBoardWithZeros();
    void createTheBoard();
    bool checkIfItsAFileCommand(const string command);
    string getColumnHelper(string player, int* inputType);
    int getRowHelper(char column);
    void getInputFromPlayer(string player, string& input, char* column, int* row);
    void fileOperations(const string& input);
    void play(int* rowInput, int* columnInput, char playerSign); //plays the user
    bool play(); //plays the computer
    int playerVersusPlayer();
    void displayBoard(); //displays the current board on the screen
    int isItAScore(int row, int column, char player); //check if the game is over
    bool isTheBoardAvailable(); //check if the game is available
    void readFrom(const string& filename); //read from file
    void writeTo(const string& filename); //write to file
    void displayTheScore(int player_1, int player_2_or_computer, int mode);
    vector<int> calculateCounts(int row, int column, char player);
    int bestOdds();
    void gameInitialization();
    int computerVersusPlayer();
    void playHelper(int* rowInput, int* columnInput, char playerSign);
    int playGame();
	bool whichUserIsWinning(ConnectFour& other);
private:
    class Cell{ //holds the position of the cell
    public:
        Cell();
        Cell(char col, int row);

        int getColumn() const {return column;}; //inline function

        int getRow() const {return row;}; //inline function

        int getSituation() const {return situation;}; //inline function

        void setColumn(int column);

        void setRow(int row);

        void setSituation(int situation);

    private:
        int column;
        int row;
        int situation; //0 for empty, 1 for user1, 2 for computer or user2
        char character;

    };
    vector<vector<Cell> > gameCells;
    int width;
    int height;
    static int numberOfLivingCells;
    char singleOrMulti;
    int playerOrComputer;
    const int countArraySize = 4;
    static int object;
    static int loaded;
    int gameNumber;
};



#endif //CONNECTFOUR_H
