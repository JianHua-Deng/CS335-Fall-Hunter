#include "Card.hpp"
//#include "ActionCard.hpp"
//#include "Deck.hpp"
//#include "Hand.hpp"
//#include "Player.hpp"
//#include "PointCard.hpp"

int main(){

    Card *c1 = new Card();
    std::cout << c1->getInstruction() << "\n";
    c1->setInstruction("Im gay");
    std::cout << c1->getInstruction() << "\n";
    return 0;
}