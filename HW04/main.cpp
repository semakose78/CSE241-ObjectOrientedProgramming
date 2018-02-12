#include <iostream>
#include "ConnectFour.h"

//sema köse
//141044002
//HW04

int main(int argc, char** argv) {
    //std::cout << "Hello, World!" << std::endl;
    string filename;
    int ret;

    cin>>singleOrMultiGlob;
    

    int objectInput;
    int firstGameAvailable = 0;
    int secondGameAvailable = 0;
    int thirdGameAvailable = 0;
    int fourthGameAvailable = 0;
    int fifthGameAvailable = 0;


    if(singleOrMultiGlob == 'S'){
    	cin>>filename;
    	ConnectFour firstGame(filename);
        firstGame.setSingle('S');
        firstGame.setTheGamingMode();
        firstGame.playGame();
    }else if(singleOrMultiGlob == 'M'){
        //cout<<"Obje 1:"<<endl;
        cin>>filename;
        ConnectFour firstGame(filename);
        firstGame.setTheGamingMode();
        firstGame.setGameNumber(1);
        //firstGame.playGame();
        //cout<<"Obje 2:"<<endl;
        cin>>filename;
        ConnectFour secondGame(filename);
        secondGame.setTheGamingMode();
        secondGame.setGameNumber(2);
        //secondGame.playGame();
        //cout<<"Obje 3:"<<endl;
        cin>>filename;
        ConnectFour thirdGame(filename);
        thirdGame.setTheGamingMode();
        thirdGame.setGameNumber(3);
        //thirdGame.playGame();
        //cout<<"Obje 4:"<<endl;
        cin>>filename;
        ConnectFour fourthGame(filename);
        fourthGame.setTheGamingMode();
        fourthGame.setGameNumber(4);
        //fourthGame.playGame();
        //cout<<"Obje 5:"<<endl;
        cin>>filename;
        ConnectFour fifthGame(filename);
        fifthGame.setTheGamingMode();
        fifthGame.setGameNumber(5);
        //fifthGame.playGame();
        while(1){
            //cout<<"Obje seçiniz : ";
            cin>>inputObject;
            cout<<"Object: "<<inputObject<<endl;
            //firstGame.setObject(objectInput);
            if((inputObject == 1) && !firstGameAvailable)
                firstGameAvailable = firstGame.playGame();
            else if((inputObject== 2) && !secondGameAvailable){
							secondGameAvailable = secondGame.playGame();
							if(firstGame == secondGame)
									cout<<endl<<"The first game and the second game are same"<<endl<<endl;
							else if(firstGame != secondGame)
									cout<<endl<<"The first game and the second game are different"<<endl<<endl;
						}
            else if((inputObject == 3) && !thirdGameAvailable)
                thirdGameAvailable = thirdGame.playGame();
            else if((inputObject == 4) && !fourthGameAvailable)
                fourthGameAvailable = fourthGame.playGame();
            else if((inputObject == 5) && !fifthGameAvailable)
                fifthGameAvailable = fifthGame.playGame();
        }
    }


    return 0;
}
