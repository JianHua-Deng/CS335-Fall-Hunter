#include "Card.hpp"
#include "ActionCard.hpp"

/**
 * @post: Construct a new Action Card object
*/
ActionCard::ActionCard():Card(){}

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
    }
    
    
    //Check if instruction were valid by splitting the word into a vector
    std::string instruction = this->getInstruction();
    std::vector<std::string> word_list;

    std::string word;
    std::stringstream stringstream(instruction);

    //Seperating instruction with space, and pushing it to a vector
    while(std::getline(stringstream, word, ' ')){
        word_list.push_back(word);
    }

    if(word_list.empty()){
        return false;
    }else if(word_list.size() == 3 && (word_list[0] == "DRAW" || word_list[0] == "PLAY")){
        if(isInteger(word_list[1]) && word_list[2] == "CARD(S)"){
            return true;
        }
    }else if(word_list.size() == 2 && word_list[0] == "REVERSE" && word_list[1] == "HAND"){
        return true;
    }else if(word_list.size() == 4 && word_list[0] == "SWAP" && word_list[1] == "HAND" && word_list[2] == "WITH" && word_list[3] == "OPPONENT"){
        return true;
    }

    return false;
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
    std::cout << "Card: " << "\n" << "[";
    for(int i = 0; i < 80; i++){
        std::cout << this->getImageData()[i];
    }
    std::cout << "]"<< "\n";

}

bool ActionCard::isInteger(std::string& integer){
    for(char x : integer){
        if(!std::isdigit(x)){
            return false;
        }
    }
    return true;
}