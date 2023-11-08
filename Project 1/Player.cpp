#include "Player.hpp"
/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name: Jianhua Deng
Date: 11/07/2023 
Player.cpp implements the Player class.
*/

/**
 * @post: Construct a new Player object
 */
Player::Player(){

    this->score_ = 0;
    this->hand_ = Hand();
    this->opponent_ = nullptr;
    this->actiondeck_ = nullptr; 
    this->pointdeck_ = nullptr;
    

}

/**
 * @post: Destroy the Player object
 */
Player::~Player(){
    //conditions for when the opponent and current player has the same pointdeck, avoiding opponent to delete something that no longer exists, causing seg fault
    if(this->opponent_ != nullptr && this->getActionDeck() == this->opponent_->getActionDeck()){
        this->opponent_->setActionDeck(nullptr);
    }
    delete this->actiondeck_;

    //conditions for when the opponent and current player has the same pointdeck, avoiding opponent to delete something that no longer exists, causing seg fault
    if(this->opponent_ != nullptr && this->getPointDeck() == this->opponent_ ->getPointDeck()){
        this->opponent_->setPointDeck(nullptr);
    }
    delete this->pointdeck_;

    //Avoid deleting opponent to avoid double free as opponent will call destructor on itself
    if(this->opponent_ != nullptr){
        this->setOpponent(nullptr);
    }
    this->opponent_ = nullptr;
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
/**/
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
    //delete this->actiondeck_;
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
    //delete this->pointdeck_;
    this->pointdeck_ = pointdeck;
}
/**
 * @return: a pointer to the player's point deck
 */
Deck<PointCard>* Player::getPointDeck(){
    return this->pointdeck_;
}