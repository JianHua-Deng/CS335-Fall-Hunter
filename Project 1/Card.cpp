#include "Card.hpp"

//Default Constructor
Card::Card(){
    this->setInstruction("");
    this->bitmap_ = new int[80];
    this->setDrawn(false);
}

//Copy Constructor
Card::Card(const Card& rhs){

        //Creating this because. copy constructor is used to copy exisiting object to a newly created object, meaning the new instance never had a dynamic array of size 80
        this->bitmap_ = new int[80];

        //Condition statements for setting types
        if(rhs.getType() == "ACTION_CARD"){
            this->setType(ACTION_CARD);
        }else{
            this->setType(POINT_CARD);
        }
        this->setInstruction(rhs.instruction_);
        this->drawn_= rhs.drawn_;

        if(rhs.bitmap_ != nullptr){
            for(int i = 0; i < 80; i++){
                this->bitmap_[i] = rhs.getImageData()[i];
            }//end for loop
        }//end if condition

}

//Copy Assignment Operators
Card& Card::operator=(const Card& rhs){
    if(this != &rhs){
        //Condition statements for setting types
        if(rhs.getType() == "ACTION_CARD"){
            this->setType(ACTION_CARD);
        }else{
            this->setType(POINT_CARD);
        }
        this->instruction_ = rhs.instruction_;
        this->drawn_= rhs.drawn_;

        if(rhs.bitmap_ != nullptr){
            for(int i = 0; i < 80; i++){
                this->bitmap_[i] = rhs.bitmap_[i];
            }//end for loop
        }//end if condition
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
    this->instruction_ = rhs.instruction_;
    this->drawn_ = rhs.drawn_;
    this->bitmap_ = rhs.bitmap_;
    rhs.bitmap_ = nullptr;


}

//Move Assignment Operator
Card& Card::operator=(Card&& rhs){

    //We needed this in move assignment operator but not in move constructor because this is used when we moving data to a newly allcoated object, meaning we have to delete the exisiting data first
    

    if(this != &rhs){
        if(rhs.getType() == "ACTION_CARD"){
            this->setType(ACTION_CARD);
        }else{
            this->setType(POINT_CARD);
        }
        this->instruction_ = rhs.instruction_;
        this->drawn_ = rhs.drawn_;
        
        delete[] this->bitmap_;
        this->bitmap_ = rhs.bitmap_;
        rhs.bitmap_ = nullptr;

    }

    return *this;
}

//Deconstructor
Card::~Card(){
    delete[] this->bitmap_;
}

//Accessor for CardType
std::string Card::getType() const{
    if(this->cardType_ == ACTION_CARD){
        return "ACTION_CARD";
    }else{
        return "POINT_CARD";
    }
}

/*
copy constructor/assignment operator for loop for bitmap
move assignmetn/operator, use std::move
*/

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

bool Card::isInteger(const std::string& integer){
    for(char x : integer){
        if(!std::isdigit(x)){
            return false;
        }
    }
    return true;
}


