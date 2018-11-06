#include <iostream>
#include "player.h"

using namespace std;

Player::Player() {
    myName="";
    myHand.resize(0);
    myBook.resize(0);
}

void Player::addCard(Card c)  
{
    myHand.push_back(c);        //adds a card to the hand
}
