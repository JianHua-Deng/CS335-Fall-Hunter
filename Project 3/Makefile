
CXXFLAGS=-g

main: main.o $(OBJECTS)
	g++ -g -o main $(OBJECTS) main.o

main.o: main.cpp NearestNeighbor.hpp GreedyTSP.hpp



clean:
	rm -f main.o $(OBJECTS) main
