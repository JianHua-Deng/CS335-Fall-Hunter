#include "Card.hpp"
#include "ActionCard.hpp"

/**
 * @post: Construct a new Action Card object
*/
ActionCard::ActionCard(){

}

/**
 * @return true if the card is playable, false otherwise
 * For a card to be playable, it has to be drawn and the instruction has to be valid
 * Valid instructions:
 * DRAW x CARD(S) : assume x is a positive integer
 * PLAY x CARD(S) : assume x is a positive integer
 * REVERSE HAND : reverse the order of the cards in the hand
 * SWAP HAND WITH OPPONENT : swap the hand with the opponent
*/
bool ActionCard::isPlayable(){

    //check if drawn
    if(!(this->getDrawn())){
        return false;
    }else{
        return true;
    }
    
    /*
    //Check if instruction were valid by splitting the word into a vector
    std::string instruction = this->getInstruction();

    std::vector<std::string> word_list;
    std::string word;
    std::stringstream stringstream(instruction);

    while(std::getline(stringstream, word, ' ')){
        word_list.push_back(word);
    }

    for(int i = 0; i < word_list.size(); i++){
        std::cout << word_list[i] << "\n";
    }
    */
}

/**
 * @post: Print the ActionCard in the following format:
 * Type: [CardType]
 * Instruction: [Instruction]
 * Card: 
 * [ImageData]
 * 
 * Note: For [ImageData]: If there is no image data, print "No image data" instead
 */
void ActionCard::Print() const{

    std::cout << "Type: " << "["<< this->getType() << "]"<< "\n";
    std::cout << "Instruction: " << "["<< this->getInstruction() << "]"<< "\n";
    std::cout << "Card: " << "\n" << "["<< this->getImageData() << "]"<< "\n";

}