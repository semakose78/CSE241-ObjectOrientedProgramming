//sema köse
//141044002
//HW04

#ifndef HW04_CONNECTFOUR_H
#define HW04_CONNECTFOUR_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
static char singleOrMultiGlob;
static int inputObject;
class Cell;
class ConnectFour {
public:
    ConnectFour();
    ConnectFour(int w, int h);
    ConnectFour(const string filename);
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
    void setFileName();
    inline void setSingle(char a){singleOrMulti = a;};
    int setTheBoardSize();
    void setTheGamingMode();
    void setGameNumber(int num){gameNumber = num;};
    void fillTheBoardWithZeros();
    void createTheBoard();
    bool checkIfItsAFileCommand(const string command);
    string getColumnHelper(string player, int* inputType);
    int getRowHelper(char column);
    void getInputFromPlayer(string player, string& input, char* column, int* row);
    ConnectFour fileOperations(const string& input);
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
    int countRow();
    int countCol();
    bool operator==(const ConnectFour& other) const;
    bool operator!=(const ConnectFour& other) const;


private:
    class Cell{ //holds the position of the cell
    public:
        Cell();
        Cell(char col, int row);
	Cell(int st);

        int getColumn() const {return column;}; //inline function

        int getRow() const {return row;}; //inline function

        int getSituation() const {return situation;}; //inline function

        void setColumn(int column);

        void setRow(int row);

        void setSituation(int st);

        bool operator==(const Cell& other) const;
        Cell operator++(){
		Cell temp;
		temp.situation = situation;
		if(situation == 0)
			situation = 1; //empty to user1
		else if(situation == 1)
			situation = 2; //user1 to user2
		else if(situation == 2)
			situation = 4; //user2 to comp
		return temp;
	
	};
        Cell operator++(int){
		if(situation == 0)
			situation = 1; //empty to user1
		else if(situation == 1)
			situation = 2; //user1 to user2
		else if(situation == 2)
			situation = 4; //user2 to comp
		return Cell(situation);
	};
        Cell operator--(){
		Cell temp;
		temp.situation = situation;
		if(situation == 4)
			situation = 2; //comp to user2
		else if(situation == 2)
			situation = 1; //user2 to user1
		else if(situation == 1)
			situation = 0; //user1 to empty
		return temp;
	};
        Cell operator--(int){
		if(situation == 4)
			situation = 2; //comp to user2
		else if(situation == 2)
			situation = 1; //user2 to user1
		else if(situation == 1)
			situation = 0; //user1 to empty
		return Cell(situation);
	};

        void displayHelper(ostream& outStream) const{
            outStream<<"Column: " << getColumn() <<endl
                     << "Row: " << getRow() <<endl
                     << "Situation " << getSituation() <<endl;
        }
        void insertionHelper(istream& inStream){
            int col, row, sit;

            inStream>>col>>row>>sit;

            setColumn(col);
            setRow(row);
            setSituation(sit);
        }
        friend ostream& operator<<(ostream& outStream, const ConnectFour::Cell& obj){
            obj.displayHelper(outStream);
            return outStream;
        };
        friend istream& operator>>(istream& inStream, ConnectFour::Cell& obj){

            obj.insertionHelper(inStream);

            return inStream;
        };

    private:
        int column;
        int row;
        int situation; //0 for empty, 1 for user1, 2 for computer or user2, 3 unusuable, 4 computer
        char character;

    };
    Cell** gameBoard;
    int width;
    int height;
    static int numberOfLivingCells;
    char singleOrMulti;
    int playerOrComputer;
    const int countArraySize = 4;
    static int object;
    static int loaded;
    int gameNumber;
    string fileNameBoard;
};














#endif //HW04_CONNECTFOUR_H
