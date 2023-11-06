#include "Player.hpp"
/**
 * @post: Construct a new Player object
 */
Player::Player(){

    this->score_ = 0;
    this->opponent_ = nullptr;
    this->actiondeck_ = nullptr; 
    this->pointdeck_ = nullptr;
    

}

/**
 * @post: Destroy the Player object
 */
Player::~Player(){

}

/**
 * @return the player's hand
 */
const Hand& Player::getHand() const{
    return this->hand_;
}
/**
 * @post: Set the player's hand
 * @param const reference to a hand object
 */
void Player::setHand(const Hand& hand){
    this->hand_ = hand;
}

/**
 * @return the Player's current score
 */
int Player::getScore() const{
    return this->score_;
}
/**
 * @post: Set the player's score
 * @param: score 
 */
void Player::setScore(const int& score){
    this->score_ = score;
}

/**
 * @post: Play a given action card
 * @param: an Actioncard object
 * Begin the function by reporting the instruction of the card:
 * PLAYING ACTION CARD: [instruction]
 */
void Player::play(ActionCard&& card){
    
    std::string instruction = card.getInstruction();
    std::cout << "PLAYING ACTION CARD: " << instruction << "\n";

    //splitting the instruction into a vector
    std::vector<std::string> word_list;
    std::string word;
    std::stringstream stringstream(instruction);

    while(std::getline(stringstream, word, ' ')){
        word_list.push_back(word);
    }
    
    //Checking the different instruction of ActionCard
    if(word_list[0] == "PLAY"){
        for(int i = 0; i < std::stoi(word_list[1]); i++){
            this->playPointCard();
        }
    }else if(word_list[0] == "DRAW"){
        for(int i = 0; i < std::stoi(word_list[1]); i++){
            this->drawPointCard();
        }            
    }else if(word_list[0] == "REVERSE"){
        this->hand_.Reverse();

    }else if(word_list[0] == "SWAP"){
        if(this->opponent_ != nullptr){
            std::swap(this->hand_, this->opponent_->hand_);
        }
        
    }
    
}

/**
 * @post: Draw a point card and place it in the player's hand
 */
void Player::drawPointCard(){
    if(this->pointdeck_ != nullptr){
        this->hand_.addCard(this->pointdeck_->Draw());
    }

}
/**
 * @post: Play a point card from the player's hand and update the player's score
 */
void Player::playPointCard(){
    if(!(this->hand_.isEmpty())){
        this->score_ += this->hand_.PlayCard();
    }
}

/**
 * @post: Set the opponent of the player
 * @param a pointer to a Player opponent 
 */
void Player::setOpponent(Player* opponent){
    this->opponent_ = opponent;
}
/**
 * @return: a pointer to the player's opponent
 */
Player* Player::getOpponent(){
    return this->opponent_;
}

/**
 * @post: set the action deck of the player 
 * @param: A pointer to a deck holding Action cards 
 */
void Player::setActionDeck(Deck<ActionCard>* actiondeck){
    this->actiondeck_ = actiondeck;
}
/**
 * @return a pointer to the player's action deck
 */
Deck<ActionCard>* Player::getActionDeck(){
    return this->actiondeck_;
}

/**
 * @post: set the point deck of the player
 * @param: A pointer to a deck holding Point cards
 */
void Player::setPointDeck(Deck<PointCard>* pointdeck){
    this->pointdeck_ = pointdeck;
}
/**
 * @return: a pointer to the player's point deck
 */
Deck<PointCard>* Player::getPointDeck(){
    return this->pointdeck_;
}