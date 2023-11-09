#include "Card.hpp"
#include "PointCard.hpp"
/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name: Jianhua Deng
Date: 11/07/2023 
PointCard.cpp implement the PointCard class and inherits from the Card Class.
*/
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
    return (std::stoi(getInstruction()) > 0 && getDrawn());//if drawn is true and instruction is a number greater than 0
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

    std::cout << "Type: " << this->getType() << "\n";
    std::cout << "Points: " << this->getInstruction() << "\n";

    if(this->getImageData() == nullptr){
        std::cout << "Card: " << std::endl << "No image data" << std::endl;
    }else{
        std::cout << "Card: "<< std::endl << "[" << this->getImageData()[0];
        for(int i = 1; i < 80; i++){
            std::cout << ", " << this->getImageData()[i];
        }
        std::cout << "]" << std::endl;
    }  

}