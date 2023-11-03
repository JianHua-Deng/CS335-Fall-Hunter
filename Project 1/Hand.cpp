#include "Hand.hpp"

// Big Five and constructor
/**
 * @post: Construct a new Hand object
 */
Hand::Hand(){
    this->cards_ = std::deque<PointCard>();
}
/**
 * @post: Destroy the Hand object
 */
Hand::~Hand(){
    this->cards_.clear();
}
/**
 * Copy Constructor
 * @param: other Hand object
 */
Hand::Hand(const Hand& other){

}
/**
 * Copy Assignment Operator
 * @param: other Hand object
 * @return this Hand 
 */
Hand& Hand::operator=(const Hand& other){


    return *this;
}
/**
 * Move Constructor
 * @param: other Hand object
 */
Hand::Hand(Hand&& other){

}
/**
 * Move assignment operator
 * @param: other Hand object
 * @return this Hand
 */
Hand& Hand::operator=(Hand&& other){

    return *this;
}

/**
 * @return Hand
 */
const std::deque<PointCard>& Hand::getCards() const{

}

/**
 * @post: Add a card to the hand
 * @param PointCard object
 */
void Hand::addCard(PointCard&& card){
    this->cards_.push_back(card);
}

/**
 * @return true if hand is empty, false otherwise
 */
bool Hand::isEmpty() const{
    if(this->cards_.size() > 0){
        return false;
    }else{
        return true;
    }
}

/**
 * @post: Reverse the hand
 */
void Hand::Reverse(){

}

/**
 * @post: Play the card at the front of the hand, removing it from the hand
 * Throws an exception if the hand is empty or the card is not playable
 * If the card is not playable, the card is removed from the hand
 * @return the points earned from playing the card
 */
int Hand::PlayCard(){
    if(this->cards_.empty()){
        throw EMPTY;
    }else if (!(this->cards_.front().isPlayable())){
        this->cards_.pop_front();
        throw UNPLAYABLE;
    }else{
        std::string strPoint = this->cards_.front().getInstruction();
        int point = std::stoi(strPoint);
        
        this->cards_.pop_front();
        return point;
    }
}