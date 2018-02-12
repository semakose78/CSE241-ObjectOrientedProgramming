//
// Sema Köse
// 141044002
// HW05
//

#ifndef HW05_CONNECTFOURPLUSUNDO_H
#define HW05_CONNECTFOURPLUSUNDO_H


#include "ConnectFourAbstract.h"
#include <iostream>
#include <vector>

namespace ConnectFour{
    class ConnectFourPlusUndo: public ConnectFourAbstract{
    public:
        int isItAScore(int row, int column, char player) override ;
        void play(int* rowInput, int* columnInput, char playerSign) override;
        bool play() override ; //plays the computer
    private:
        vector<int> movesRows;
        vector<int> movesCols;
    };
}



#endif //HW05_CONNECTFOURPLUSUNDO_H
