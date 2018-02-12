//
// Sema Köse
// 141044002
// HW05
//

#ifndef HW05_CELL_H
#define HW05_CELL_H

namespace ConnectFour{
    class Cell{ //holds the position of the cell
    public:
        Cell();
        Cell(int st);
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
}


#endif //HW05_CELL_H
