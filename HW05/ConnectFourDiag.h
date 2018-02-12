//
// Sema Köse
// 141044002
// HW05
//

#ifndef HW05_CONNECTFOURDIAG_H
#define HW05_CONNECTFOURDIAG_H

#include "ConnectFourAbstract.h"

namespace ConnectFour{
    class ConnectFourDiag: public ConnectFourAbstract{
    public:
        int isItAScore(int row, int column, char player);
    };
}

#endif //HW05_CONNECTFOURDİAG_H
