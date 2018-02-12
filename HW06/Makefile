output: main.o GTUIterator.o GTUMap.o GTUSet.o
	g++ -std=c++11 main.o GTUIterator.o GTUMap.o GTUSet.o -o exe

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

GTUIterator.o: GTUIterator.cpp GTUSet.h
	g++ -c -std=c++11 GTUIterator.cpp

GTUMap.o: GTUMap.cpp GTUMap.h
	g++ -c -std=c++11 GTUMap.cpp

GTUSet.o: GTUSet.cpp GTUSet.h
	g++ -c -std=c++11 GTUSet.cpp

clean:
	rm *.o exe
