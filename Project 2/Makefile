OBJECTS=HalfSelectionSort.o
CXXFLAGS=-g

main: main.o $(OBJECTS)
	g++ -g -o main $(OBJECTS) main.o

main.o: main.cpp HalfSelectionSort.o

HalfSelectionSort.o: HalfSelectionSort.cpp HalfSelectionSort.hpp

clean:
	rm -f main.o $(OBJECTS) main
