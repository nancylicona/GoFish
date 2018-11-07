#include <iostream>
#include "player.h"
#include <iterator>

using namespace std;

Player::Player() {
    myName="";          //set to empty string
    myHand.resize(0);   //set to size 0
    myBook.resize(0);   //set to size 0
}

void Player::addCard(Card c)
{
    myHand.push_back(c);                            //adds a card to the hand
}


void Player::bookCards(Card c1, Card c2){
    if(c1.getRank()==c2.getRank()){                  // if cards are the same rank and spades
        myBook.push_back(c1);                       //Add card1 to the book
        myBook.push_back(c2);                       //Add card2 to the book
    }
}


//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards tha make the pair.
bool Player::checkHandForBook(Card &c1, Card &c2) {
    Card card1;     //declare card1
    Card card2;     //declare card2
    vector<Card>::iterator iter;        //declare iter pointer
    vector<Card>::iterator iter2;       //declare iter2 pointer
    for (iter = myHand.begin(); iter != myHand.end(); iter++) {        //loops through all the hand
        card1 = *iter;             //define card1
        for (iter2 = iter + 1; iter2 != (myHand.end()+1); iter2++) {
            card2 = *iter2;           //define card2
            if (card1.getRank() == card2.getRank()) {       //if the ranks are the same
                c1 = card1;       //store card1
                c2 = card1;       //store card2
                return true;      //pair found
            }
        }
    }
    return false;           //pair not found
}

//OPTIONAL
// comment out if you decide to not use it
//Does the player have a card with the same rank as c in her hand?
bool Player::rankInHand(Card c) const{                                           //Since f(const) const_iterator
    Card cardpointer;
    vector<Card>::const_iterator pointer;                                       //Pointer that goes through the hand
    for(pointer=myHand.begin(); pointer!=myHand.end(); pointer++ ){             //For loop to go through the vector array
        cardpointer = *pointer;
        if (c.getRank() == cardpointer.getRank()){                              //If in the hand there it a card C then...
            return true;}                                                       //Return true
    }
    return false;                                                               //If not equal hand is found then return false
}

