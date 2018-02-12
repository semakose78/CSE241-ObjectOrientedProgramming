output: main.o ConnectFourAbstract.o ConnectFourPlus.o ConnectFourPlusUndo.o ConnectFourDiag.o Cell.o
	g++ -std=c++11 main.o ConnectFourAbstract.o ConnectFourPlus.o ConnectFourPlusUndo.o ConnectFourDiag.o Cell.o -o exe

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

ConnectFourAbstract.o: ConnectFourAbstract.cpp ConnectFourAbstract.h
	g++ -c -std=c++11 ConnectFourAbstract.cpp

ConnectFourPlus.o: ConnectFourPlus.cpp ConnectFourPlus.h
	g++ -c -std=c++11 ConnectFourPlus.cpp

ConnectFourPlusUndo.o: ConnectFourPlusUndo.cpp ConnectFourPlusUndo.h
	g++ -c -std=c++11 ConnectFourPlusUndo.cpp

ConnectFourDiag.o: ConnectFourDiag.cpp ConnectFourDiag.h
	g++ -c -std=c++11 ConnectFourDiag.cpp

Cell.o: Cell.cpp Cell.h
	g++ -c -std=c++11 Cell.cpp

clean:
	rm *.o exe
