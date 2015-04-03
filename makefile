all: Project8

Project8: Project8.cpp Implementation.o stringFunctions.o
			g++ Project8.cpp Implementation.o stringFunctions.o -o Project8
Implementation.o: Implementation.cpp
	g++ -c Implementation.cpp -o Implementation.o

stringFunctions.o: stringFunctions.cpp
				g++ -c stringFunctions.cpp -o stringFunctions.o


clean: rm -rf *.o Project8
