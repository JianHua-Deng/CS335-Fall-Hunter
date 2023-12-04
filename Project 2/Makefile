
CXXFLAGS=-g

main: main.o $(OBJECTS)
	g++ -g -o main $(OBJECTS) main.o

main.o: main.cpp HalfSelectionSort.hpp StandardSort.hpp MergeSort.hpp InPlaceMergeSort.hpp HalfHeapSort.hpp QuickSelect.hpp WorstCaseQuickSelect.hpp MedianOfMediansMethod.hpp



clean:
	rm -f main.o $(OBJECTS) main
