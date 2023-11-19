OBJECTS=HalfSelectionSort.o StandardSort.o MergeSort.o
CXXFLAGS=-g

main: main.o $(OBJECTS)
	g++ -g -o main $(OBJECTS) main.o

main.o: main.cpp HalfSelectionSort.o

HalfSelectionSort.o: HalfSelectionSort.cpp HalfSelectionSort.hpp

StandardSort.o: StandardSort.cpp StandardSort.hpp

MergeSort.o: MergeSort.cpp MergeSort.hpp

clean:
	rm -f main.o $(OBJECTS) main
