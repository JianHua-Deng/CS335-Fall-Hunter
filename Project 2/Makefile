OBJECTS=HalfSelectionSort.o StandardSort.o MergeSort.o InPlaceMergeSort.o HalfHeapSort.o
CXXFLAGS=-g

main: main.o $(OBJECTS)
	g++ -g -o main $(OBJECTS) main.o

main.o: main.cpp HalfSelectionSort.hpp StandardSort.hpp MergeSort.hpp InPlaceMergeSort.hpp HalfHeapSort.hpp

HalfSelectionSort.o: HalfSelectionSort.cpp HalfSelectionSort.hpp

StandardSort.o: StandardSort.cpp StandardSort.hpp

MergeSort.o: MergeSort.cpp MergeSort.hpp

InPlaceMergeSort.o: InPlaceMergeSort.cpp InPlaceMergeSort.hpp

HalfHeapSort.o: HalfHeapSort.cpp HalfHeapSort.hpp

clean:
	rm -f main.o $(OBJECTS) main
