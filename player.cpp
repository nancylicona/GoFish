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
    myHand.push_back(c);                            //adds a card to the hand
}


void Player::bookCards(Card c1, Card c2){
    if(c1==c2){                                     // if cards are the same rank and spades
        myBook.push_back(c1);                       //Add card1 to the book
        myBook.push_back(c2);                       //Add card2 to the book
    }
}

