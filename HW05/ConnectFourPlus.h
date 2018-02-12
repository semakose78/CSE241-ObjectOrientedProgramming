//
// Sema Köse
// 141044002
// HW05
//

#ifndef HW05_CONNECTFOURPLUS_H
#define HW05_CONNECTFOURPLUS_H

#include "ConnectFourAbstract.h"

namespace ConnectFour{
    class ConnectFourPlus: public ConnectFourAbstract{
    public:
        int isItAScore(int row, int column, char player);
    };
}

#endif //HW05_CONNECTFOURPLUS_H
