#include "Card.hpp"
#include "PointCard.hpp"
/**
 * @post: Construct a new Point Card object
 */
PointCard::PointCard():Card(){
    
    this->setType(POINT_CARD);
}
/**
 * @return true if the card is playable, false otherwise
 * For a card to be playable, it has to be drawn and the instruction has to be a valid number
*/
bool PointCard::isPlayable(){
    if(!this->getDrawn()){
        return false;
    }

    if(!(isInteger(this->getInstruction()))){
        return false;
    }else{
        return true;
    }
}
/**
 * @post: Print the Point Card in the following format:
 * Type: [CardType]
 * Points: [Instruction]
 * Card: 
 * [ImageData]
 * 
 * Note: For [ImageData]: If there is no image data, print "No image data" instead
 */
void PointCard::Print() const{

    std::string data;

    std::cout << "Type: " << this->getType() << "\n";
    std::cout << "Instruction: " << this->getInstruction() << "\n";

    if(this->getImageData() == nullptr){
        std::cout << "Card: " << "\n" << "No image data" << "\n";
    }else{
        for(int i = 0; i < 80; i++){
            data += this->getImageData()[i];
        }
        std::cout << "Card: " << "\n"  << data  << "\n";
    }  

}