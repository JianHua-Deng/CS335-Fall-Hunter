OBJECTS=HalfSelectionSort.o StandardSort.o MergeSort.o InPlaceMergeSort.o
CXXFLAGS=-g

main: main.o $(OBJECTS)
	g++ -g -o main $(OBJECTS) main.o

main.o: main.cpp HalfSelectionSort.o

HalfSelectionSort.o: HalfSelectionSort.cpp HalfSelectionSort.hpp

StandardSort.o: StandardSort.cpp StandardSort.hpp

MergeSort.o: MergeSort.cpp MergeSort.hpp

InPlaceMergeSort.o: InPlaceMergeSort.cpp InPlaceMergeSort.hpp

clean:
	rm -f main.o $(OBJECTS) main
