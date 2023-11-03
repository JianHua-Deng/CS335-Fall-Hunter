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
    this->cards_ = std::deque<PointCard>();
    std::copy(other.cards_.begin(), other.cards_.end(), this->cards_.begin());
}
/**
 * Copy Assignment Operator
 * @param: other Hand object
 * @return this Hand 
 */
Hand& Hand::operator=(const Hand& other){
    if(this != &other){
        std::copy(other.cards_.begin(), other.cards_.end(), this->cards_.begin());
    }

    return *this;
}
/**
 * Move Constructor
 * @param: other Hand object
 */
Hand::Hand(Hand&& other){
    this->cards_ = std::deque<PointCard>();

}
/**
 * Move assignment operator
 * @param: other Hand object
 * @return this Hand
 */
Hand& Hand::operator=(Hand&& other){
    if(this != &other){

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
    std::reverse(this->cards_.begin(), this->cards_.end());
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