OBJECTS=Card.o ActionCard.o Deck.o Hand.o Player.o PointCard.o
CXXFLAGS=-g

main: main.o $(OBJECTS)
	g++ -g -o main main.o $(OBJECTS)

main.o: main.cpp Card.hpp ActionCard.hpp Deck.hpp Hand.hpp Player.hpp PointCard.hpp

Card.o: Card.cpp Card.hpp

ActionCard.o: ActionCard.cpp ActionCard.hpp Card.hpp

Deck.o: Card.cpp Card.hpp

Hand.o: Hand.cpp Hand.hpp

Player.o: Player.cpp Player.hpp

PointCard.o: PointCard.cpp PointCard.hpp Card.hpp

clean:
	rm -f main.o $(OBJECTS)
