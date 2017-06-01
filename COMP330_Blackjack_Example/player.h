#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include <vector>

class Player
{
public:
    Player();
    bool inGame(bool a);
    void PrintHand();
    void AddCard(Card* newCard);
    int GetScore();
    bool CheckForAce();

protected:
    std::vector<Card*> hand_;
    int score_;
};

#endif // PLAYER_H
