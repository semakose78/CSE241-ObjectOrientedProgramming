//
// Sema Köse
// 141044002
// HW05
//

#include "Cell.h"
using namespace ConnectFour;
Cell::Cell(int st){
    situation = st;
}
Cell::Cell(char col, int row){
    setColumn(col);
    setRow(row);
}
Cell::Cell(){
    setColumn(0);
    setRow(0);
};

inline void Cell::setColumn(int column) {
    Cell::column = column;
}

inline void Cell::setRow(int row) {
    Cell::row = row;
}

void Cell::setSituation(int st) {
    situation = st;
}
