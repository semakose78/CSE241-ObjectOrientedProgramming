output: main.o connectFour.o
	g++ -std=c++11 main.o connectFour.o -o exe

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

connectFour.o: connectFour.cpp connectFour.h
	g++ -c -std=c++11 connectFour.cpp

clean:
	rm *.o exe
