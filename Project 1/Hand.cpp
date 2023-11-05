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
        //std::copy(other.cards_.begin(), other.cards_.end(), this->cards_.begin());
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
        this->cards_ = std::move(other.cards_);
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

    std::deque<PointCard> reversedCards;
    for(int i = this->cards_.size() - 1; i >= 0; i--){
        reversedCards.push_back(this->cards_[i]);
    }
    this->cards_ = std::move(reversedCards);
    

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