//
// Sema Köse
// 141044002
// HW03
// main.cpp

#include "connectFour.h"
int ConnectFour::object = 0;
int main() {
    int objectInput;
    ConnectFour firstGame;
    ConnectFour secondGame;
    ConnectFour thirdGame;
    ConnectFour fourthGame;
    ConnectFour fifthGame;
    int firstGameAvailable = 0;
	int secondGameAvailable = 0;
	int thirdGameAvailable = 0;
	int fourthGameAvailable = 0;
	int fifthGameAvailable = 0;

    firstGame.setSingleOrMulti();
    if(firstGame.getSingleOrMulti() == 'S'){
        firstGame.gameInitialization();
        firstGame.playGame();
    }else if(firstGame.getSingleOrMulti() == 'M'){
        cout<<"Obje 1:"<<endl;
        firstGame.setGameNumber(1);
        firstGame.gameInitialization();
        cout<<"Obje 2:"<<endl;
        secondGame.setGameNumber(1);
        secondGame.gameInitialization();
        cout<<"Obje 3:"<<endl;
        thirdGame.setGameNumber(1);
        thirdGame.gameInitialization();
        cout<<"Obje 4:"<<endl;
        fourthGame.setGameNumber(1);
        fourthGame.gameInitialization();
        cout<<"Obje 5:"<<endl;
        fifthGame.setGameNumber(1);
        fifthGame.gameInitialization();
        while(1){
					cout<<"Obje seçiniz : ";
					cin>>objectInput;
					if(objectInput>=1 && objectInput<=5){
						firstGame.setObject(objectInput);
						if((firstGame.getObject() == 1) && !firstGameAvailable)
							firstGameAvailable = firstGame.playGame();
						else if((firstGame.getObject() == 2) && !secondGameAvailable)
							secondGameAvailable = secondGame.playGame();
						else if((firstGame.getObject() == 3) && !thirdGameAvailable)
							thirdGameAvailable = thirdGame.playGame();
						else if((firstGame.getObject() == 4) && !fourthGameAvailable)
							fourthGameAvailable = fourthGame.playGame();
						else if((firstGame.getObject() == 5) && !fifthGameAvailable)
							fifthGameAvailable = fifthGame.playGame();
					}
					else
						cout<<"Lütfen geçerli bir obje seçiniz!"<<endl;
					cin.clear();
					cin.ignore(1000, '\n');
			
		}
    }
    return 0;
}
