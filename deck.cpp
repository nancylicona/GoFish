#include <iostream>
#include "deck.h"


using namespace std;

Deck::Deck()           // pristine, sorted deck
{   int j=1;
    for(int suit = Card::spades; suit<=Card::clubs; suit++){        //casting the numbers for suits
        Card::Suit  suit2 = static_cast <Card::Suit> (suit); // Casting???? not understanding
        for(int r=0; r<13;r++){             //
            myCards[j] = Card(r,(Card::Suit)suit);          //
            j++;                //
        }
    }
}

void Deck::shuffle()   // shuffle the deck, all 52 cards present
{
    for(int i=0; i < SIZE; i++){             //shuffles 52 cards
        int card1 = (rand() % SIZE) + 1;       //getting random rank
        int card2 = (rand() % SIZE) + 1;        //getting random suit
        if (card1!=card2){
            int temp = card1;
            myCards[card1]=myCards[card2];
            myCards[card2]=myCards[temp];
        }
    }
}

Card Deck::dealCard()   // get a card, after 52 are dealt, fail
{
    if ((size() > 0)&&(myIndex < 51)) {
        Card dealbaby = myCards[myIndex];
        size();
        return dealbaby;
    }
    else return              //fail
}

int  Deck::size() const // # cards left in the deck
{
}
