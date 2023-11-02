OBJECTS=Card.o ActionCard.o Hand.o Player.o PointCard.o
CXXFLAGS=-g

main: main.o $(OBJECTS)
	g++ -g -o main $(OBJECTS) main.o

main.o: main.cpp Card.hpp ActionCard.hpp Hand.hpp Player.hpp PointCard.hpp

Card.o: Card.cpp Card.hpp

ActionCard.o: ActionCard.cpp ActionCard.hpp Card.hpp

Hand.o: Hand.cpp Hand.hpp

Player.o: Player.cpp Player.hpp

PointCard.o: PointCard.cpp PointCard.hpp Card.hpp

clean:
	rm -f main.o $(OBJECTS) main
