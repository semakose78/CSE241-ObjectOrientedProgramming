output: main.o connectFour.o
	g++ main.o connectFour.o -o exe

main.o: main.cpp
	g++ -c main.cpp

connectFour.o: connectFour.cpp connectFour.h
	g++ -c connectFour.cpp

clean:
	rm *.o exe
