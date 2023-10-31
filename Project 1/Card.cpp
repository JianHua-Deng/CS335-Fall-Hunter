#include "Card.hpp"

//Default Constructor
Card::Card(){
    this->setInstruction("");
    this->bitmap_ = new int[80];
    this->setDrawn(false);
}

//Copy Constructor
Card::Card(const Card& rhs){
    if(this != &rhs){

        //Condition statements for setting types
        if(rhs.getType() == "ACTION_CARD"){
            this->setType(ACTION_CARD);
        }else{
            this->setType(POINT_CARD);
        }
        this->setInstruction(rhs.getInstruction());
        //this->setImageData();
        this->setDrawn(rhs.getDrawn());        
    }
}

//Copy Assignment Operators
Card& Card::operator=(const Card& rhs){
    if(this != &rhs){
  
    }

    return *this;
}

//Move Constructor
Card::Card(Card&& rhs){
    if(rhs.getType() == "ACTION_CARD"){
        this->setType(ACTION_CARD);
    }else{
        this->setType(POINT_CARD);
    }
    this->setInstruction(rhs.getInstruction());
    //this->setImageData();
    this->setDrawn(rhs.getDrawn());
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
    }else{
        return "POINT_CARD";
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
    this->instruction_ = instruction;
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



