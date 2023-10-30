#include "Card.hpp"

//Default Constructor
Card::Card(){
    this->setInstruction("");
    this->setImageData(nullptr);
    this->setDrawn(false);
}

//Copy Constructor
Card::Card(const Card& rhs){
    if(this != &rhs){
        this->cardType_ = rhs.getType();
        this->instruction_ = rhs.getInstruction();
        this->bitmap_ = rhs.getImageData();
        this->drawn_ = this->getDrawn();
    }
}

//Copy Assignment Operators
Card& Card::operator=(const Card& rhs){
    if(this != &rhs){
        this->setType(rhs.getType());
        this->setInstruction(rhs.getInstruction());
        this->setImageData(rhs.getImageData());
        this->setDrawn(rhs.getDrawn());        
    }

    return *this;
}

//Move Constructor
Card::Card(Card&& rhs){

}

//Move Assignment Operator
Card& Card::operator=(Card&& rhs){

    if(this != &rhs){
        
    }

    return *this;
}

//Deconstructor
Card::~Card(){}

//Accessor for CardType
std::string Card::getType() const{
    if(this->cardType_ == ACTION_CARD){
        return "ACTION_CARD";
    }else if(this->cardType_ == POINT_CARD){
        return "POINT_CARD";
    }else{
        return "NONE";
    }
}

//Setting for CardType
void Card::setType(const CardType& type){
    this->cardType_ = type;
}

//Accessor for Instruction
const std::string& Card::getInstruction() const{
    return this->instruction_;
}

//Setter for Instruction
void Card::setInstruction(const std::string& instruction){

}

//Accessor for bitmap
const int* Card::getImageData() const{
    return this->bitmap_;
}

//Setter for bitmap
void Card::setImageData(int* data){
    this->bitmap_ = data;
}

//Getter for drawn
bool Card::getDrawn() const{
    return this->drawn_;
}

//Setter for Drawn
void Card::setDrawn(const bool& drawn){
    this->drawn_ = drawn;
}




