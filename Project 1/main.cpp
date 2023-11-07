#include "Card.hpp"
#include "ActionCard.hpp"
#include "Hand.hpp"
#include "Player.hpp"
#include "PointCard.hpp"
#include "Deck.hpp"

int main(){

    ActionCard ac1;
    ac1.setDrawn(true);
    std::cout << ac1.isPlayable() << "\n";
    ac1.setInstruction("SWAP HAND WITH OPPONENT");
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
    Deck<PointCard> deck2;
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
    deck1.AddCard(pc7);

    /*
    Hand h1;
    h1.addCard(deck1.Draw());
    h1.addCard(deck1.Draw());
    h1.addCard(deck1.Draw());

    Hand h2 = std::move(h1);

    std::cout << "printing h2 Hand:" << "\n" << "-----------------PreReverse AND Moved from h1--------------------\n";
    for(int i = 0; i < h2.getCards().size(); i++){
        h2.getCards().at(i).Print();
        std::cout << "\n---------" << "\n";
    }
    std::cout << "-----------------h1 After being moved to h2--------------------\n" << "\n";
    
    for(int i = 0; i < h1.getCards().size(); i++){
        h1.getCards().at(i).Print();
        std::cout << "\n---------" << "\n";
    }

    std::cout << "-----------------AfterReverse--------------------\n" << "\n";
    h2.Reverse();
    for(int i = 0; i < h2.getCards().size(); i++){
        h2.getCards().at(i).Print();
        std::cout << "\n---------" << "\n";
    }    

    std::cout << "11: " << h2.PlayCard() << "\n";
    */
   ///*
    std::cout << "-----------------TESTING PLAYER--------------------\n";

    Hand hand1;
    Hand oppHand;

    ActionCard action1;
    action1.setInstruction("PLAY 1 CARD(S)");
    ActionCard action2;
    action2.setInstruction("DRAW 3 CARD(S)");
    ActionCard action3;
    action3.setInstruction("SWAP HAND WITH OPPONENT");
    ActionCard action4;
    action4.setInstruction("REVERSE HAND");
    std::cout << action1.isPlayable() << "\n";
    std::cout << action2.isPlayable() << "\n";
    std::cout << action3.isPlayable() << "\n";
    std::cout << action4.isPlayable() << "\n";

    Deck<ActionCard> action_deck;

    Player* play4 = new Player();


    Player* play5 = new Player();
    Deck<ActionCard>* empAD = new Deck<ActionCard>();
    Deck<PointCard>* empPD = new Deck<PointCard>;
    play4->setActionDeck(empAD);
    play4->setPointDeck(empPD);
    play4->setOpponent(play5);
    play5->setPointDeck(empPD);    
    play5->setActionDeck(empAD);
    play5->setPointDeck(empPD);
    play5->setOpponent(play4);

    Deck<ActionCard>* acdeck = new Deck<ActionCard>;
    Deck<PointCard>* ptdeck = new Deck<PointCard>;
    Hand handtest;

    //handtest.PlayCard();
    
    Player* play1 = new Player();
    Player* play2 = new Player();
    play1->setOpponent(play2);
    play1->setPointDeck(ptdeck);
    play1->setActionDeck(acdeck);
    //play1->play(std::move(action2));//draws action2
    play1->play(std::move(action1));//draws action1
    play1->play(std::move(action4));//draws action4
    play1->play(std::move(action3));//draws action3
    std::cout << "hi" << "\n";
    //std::cout << play1->getHand().isEmpty() << "\n";
    //std::cout << play2->getHand().isEmpty() << "\n";
    

    //Player* play4;
    //delete play4;
    //*/
    delete play1;
    delete play2;
    delete play4;
    delete play5;
    return 0;
}