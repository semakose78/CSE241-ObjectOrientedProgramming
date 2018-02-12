//
// Sema Köse
// 141044002
// HW05
//

#ifndef HW05_CONNECTFOUR_H
#define HW05_CONNECTFOUR_H

#include <string>
#include <vector>
#include "Cell.h"
using namespace std;
namespace ConnectFour {
    class ConnectFourAbstract{
    public:

        virtual int isItAScore(int row, int column, char player) = 0; //pure virtual function for dedicating the score


        void readFrom(const string& filename); //read from file
        void writeTo(const string& filename); //write to file
        int getWidth() const {return width;}; //inline function returns the current width
        int getHeight() const {return height;}; //inline function returns the current height
        void displayBoard(); //displays the current board on the screen
        virtual void play(int* rowInput, int* columnInput, char playerSign); //plays the user
        virtual bool play(); //plays the computer
        void setType(char t){type = t;};
        char getType(){return type;};
        bool isTheBoardAvailable(); //check if the game is available
        int playGame();

        void setWidth(int width);
        void setHeight(int height);
        void setTheGamingMode();
        void setFileName();
        int setTheBoardSize();
        int getTheGamingMode() const {return playerOrComputer;};
        static int getNumberOfLivingCells() {return numberOfLivingCells;};
        void fillTheBoardWithZeros();
        void createTheBoard();
        string getColumnHelper(string player, int* inputType);
        int getRowHelper(char column);
        void getInputFromPlayer(string player, string& input, char* column, int* row);
        bool checkIfItsAFileCommand(const string command);
        void fileOperations(const string& input);
        int computerVersusPlayer();
        int playerVersusPlayer();
        void displayTheScore(int player_1, int player_2_or_computer, int mode);

        vector<int> calculateCounts(int row, int column, char player);
        int bestOdds();
        void gameInitialization();
        void playHelper(int* rowInput, int* columnInput, char playerSign);
        int countRow();
        int countCol();

        ~ConnectFourAbstract(){
            for(int i= 0; i<getWidth() ; i++){
                delete[] gameBoard[i];
            }
            delete[] gameBoard;
        };


    protected:
        int width;
        int height;
        Cell** gameBoard;
        static int numberOfLivingCells;
        char singleOrMulti;
        int playerOrComputer;
        const int countArraySize = 4;
        static int object;
        static int loaded;
        int gameNumber;
        string fileNameBoard;
        static int turn;
        char type;
    };


}

#endif //HW05_CONNECTFOUR_H
