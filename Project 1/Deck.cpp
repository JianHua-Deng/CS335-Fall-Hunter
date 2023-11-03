//#include "Deck.hpp"
/**
 * @post: Construct a new Deck object
 */
template <typename CardType>
Deck<CardType>::Deck(){
    this->cards_ = std::vector<CardType>();
}

/**
 * @post: Destroy the Deck object 
 */
template <typename CardType>
Deck<CardType>::~Deck(){
    this->cards_.clear();
}

/**
 * @post: Add a Card to the Deck
 * @param: const reference to CardType card
 */
template <typename CardType>
void Deck<CardType>::AddCard(const CardType& card){
    this->cards_.push_back(card);
}

/**
 * @post: Draw a card from the deck
 * @pre: the deck is not empty
 * @return the right hand value of type CardType 
 */
template <typename CardType>
CardType&& Deck<CardType>::Draw(){
    
    if(!(this->IsEmpty())){
        CardType drawnCard = cards_.back();
        drawnCard.Print();
        this->cards_.pop_back();
        return std::move(drawnCard);
    }else{
        throw DECK_EMPTY;
    }

}

/**
 * @return if the deck is empty 
 */
template <typename CardType>
bool Deck<CardType>::IsEmpty() const{
    if(this->getSize() > 0){
        return false;
    }else{
        return true;
    }
}

/**
 * @post: Shuffle the deck 
 * Create a random number generator using std::mt19937 with seed 2028358904, 
 * then call std::shuffle on the vector of cards, and with the random number generator as the third argument.  
 * https://en.cppreference.com/w/cpp/algorithm/random_shuffle
 * https://en.cppreference.com/w/cpp/numeric/random/mersenne_twister_engine
 */
template <typename CardType>
void Deck<CardType>::Shuffle(){
    std::mt19937 randSeed(2028358904);
    std::shuffle(this->cards_.begin(), this->cards_.end(), randSeed);
}

/**
 * @return the size of the deck 
 */
template <typename CardType>
int Deck<CardType>::getSize() const{
    return this->cards_.size();
}

/**
 * @return the vector of cards in the deck 
 */
template <typename CardType>
std::vector<CardType> Deck<CardType>::getDeck() const{
    return this->cards_;
}