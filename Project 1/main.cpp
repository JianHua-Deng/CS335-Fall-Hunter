#include "Card.hpp"
#include "ActionCard.hpp"
//#include "Deck.hpp"
//#include "Hand.hpp"
//#include "Player.hpp"
//#include "PointCard.hpp"

int main(){

    /*
    Card *c1 = new Card();
    std::cout << c1->getInstruction() << ", "<< c1->getType() <<"\n";
    c1->setInstruction("Im gay");
    c1->setType(ACTION_CARD);
    std::cout << c1->getInstruction() << ", "<< c1->getType() <<"\n";
    */

    ActionCard ac1;
    ac1.setDrawn(true);
    ac1.Print();
    std::cout << ac1.isPlayable() << "\n";
    ac1.setInstruction("DRAW 10 CARD(S)");
    std::cout << "\n" <<ac1.isPlayable() << "\n";
    ac1.Print();
}