#include "Card.hpp"
#include "ActionCard.hpp"
//#include "Hand.hpp"
//#include "Player.hpp"
#include "PointCard.hpp"
#include "Deck.hpp"

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
    ac1.setType(ACTION_CARD);
    std::cout << "\n" << ac1.isPlayable() << "\n";
    ac1.Print();


    std::cout << "----------------------------------" << "\n";
    PointCard pc1;
    pc1.setDrawn(true);
    pc1.setInstruction("21");
    std::cout << pc1.isPlayable() << "\n";
    pc1.Print();

    std::cout << "----------------------------------" << "\n";
    PointCard pc2(pc1);
    pc2.Print();

    std::cout << "----------------------------------" << "\n";
    PointCard pc3 = std::move(pc2);
    pc3.Print();

    std::cout << "----------------------------------" << "\n";
    //pc2.Print();


    
    std::cout << "----------------------------------" << "\n";
    Deck<PointCard> deck1;
    std::cout << deck1.getSize() << "\n";
    deck1.AddCard(pc3);
    deck1.AddCard(pc2);
    std::cout << deck1.getSize() << "\n";
    PointCard pc4 = deck1.Draw();
    //pc4.Print();
    





    return 0;
}