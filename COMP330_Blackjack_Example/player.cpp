#include "player.h"
#include "card.h"

Player::Player()
{
    score_ = 0;
}

void Player::PrintHand(){
    std::cout<<"Player's Hand"<<std::endl;
    for(int i = 0; i < hand_.size(); i++){
        hand_.at(i)->PrintCard();
    }
    std::cout<<"Score: "<<score_<<std::endl;
}

void Player::AddCard(Card* newCard){
    hand_.push_back(newCard);
    score_ += newCard->GetValue();
}

int Player::GetScore(){
    return score_;
}
bool Player::CheckForAce()
{
    for(unsigned int i=0;i<hand_.size();i++)
      if(hand_.at(i)->GetFace()=="Ace")
        {
            score_=score_-hand_.at(i)->GetValue()+1;
            return true;
        }
    return false;
}
bool Player::inGame(bool a){
    return a;
}
