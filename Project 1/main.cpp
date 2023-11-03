#include "Card.hpp"
#include "ActionCard.hpp"
//#include "Hand.hpp"
//#include "Player.hpp"
#include "PointCard.hpp"
#include "Deck.hpp"

int main(){

    ActionCard ac1;
    ac1.setDrawn(true);
    std::cout << ac1.isPlayable() << "\n";
    ac1.setInstruction("DRAW 10 CARD(S)");
    ac1.setType(ACTION_CARD);
    ac1.setDrawn(true);
    std::cout << "\n" << ac1.isPlayable() << "\n";
    ac1.Print();



    std::cout << "AFTER MOVE" << "\n" << "ac2:" << "\n";
    ActionCard ac2;
    ac2 = std::move(ac1);
    ac2.Print();
    std::cout << "ac1" << "\n";
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
    PointCard pc3;
    pc3 = std::move(pc2);
    pc3.Print();

    std::cout << "----------------------------------" << "\n";
    //pc2.Print();


    
    std::cout << "----------------------------------" << "\n";
    PointCard pc4;
    PointCard pc5;
    PointCard pc6;
    Deck<PointCard> deck1;
    std::cout << deck1.getSize() << "\n";
    pc4.setInstruction("11");
    pc5.setInstruction("95");
    pc6.setInstruction("56");
    deck1.AddCard(pc4);
    deck1.AddCard(pc5);
    deck1.AddCard(pc6);
    std::cout << deck1.getSize() << "\n";
    PointCard pc7 = deck1.Draw();
    std::cout << "--------AFTER----DRAWN--------------------------" << "\n";
    pc7.Print();

    
    std::cout << "printing hand vector:" << "\n" << "-----------------PreReverse--------------------\n";
    for(int i = 0; i < deck1.getSize(); i++){
        deck1.getDeck()[i].Print();
        std::cout << "\n---------" << "\n";
    }
    std::cout << "after reverse" << "\n";
    
    





    return 0;
}