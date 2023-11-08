#include "Hand.hpp"
//std::swap(v[i], v[n-(-i)])
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
    this->cards_ = other.cards_;
}
/**
 * Copy Assignment Operator
 * @param: other Hand object
 * @return this Hand 
 */
Hand& Hand::operator=(const Hand& other){
    if(this != &other){
        this->cards_ = other.cards_;
    }

    return *this;
}
/**
 * Move Constructor
 * @param: other Hand object
 */
Hand::Hand(Hand&& other){
    this->cards_ = std::move(other.cards_);

}
/**
 * Move assignment operator
 * @param: other Hand object
 * @return this Hand
 */
Hand& Hand::operator=(Hand&& other){
    if(this != &other){
        std::swap(this->cards_, other.cards_);
    }  
    return *this;
}

/**
 * @return Hand
 */
const std::deque<PointCard>& Hand::getCards() const{
    return this->cards_;
}

/**
 * @post: Add a card to the hand
 * @param PointCard object
 */
void Hand::addCard(PointCard&& card){
    card.setDrawn(true);
    this->cards_.push_back(std::move(card));
}

/**
 * @return true if hand is empty, false otherwise
 */
bool Hand::isEmpty() const{
    return this->cards_.empty();
}

/**
 * @post: Reverse the hand
 */
void Hand::Reverse(){

    std::reverse(this->cards_.begin(), this->cards_.end());

}

/**
 * @post: Play the card at the front of the hand, removing it from the hand
 * Throws an exception if the hand is empty or the card is not playable
 * If the card is not playable, the card is removed from the hand
 * @return the points earned from playing the card
 */
int Hand::PlayCard(){

    if(this->isEmpty()){
        throw std::runtime_error("Hand is empty");
    }else if (!(this->cards_.front().isPlayable())){
        this->cards_.pop_front();
        throw std::runtime_error("Card contains unplayable instructions");
    }else{
        int point = std::stoi(this->cards_.front().getInstruction());
        this->cards_.pop_front();
        return point;
    }




}