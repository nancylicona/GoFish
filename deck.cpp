#include <iostream>
#include "deck.h"


using namespace std;

Deck::Deck()           // pristine, sorted deck
{   int j=0;		//myCards array index
    for(int suit = Card::spades; suit<=Card::clubs; suit++){        //looping through all the suits
        Card::Suit  suit2 = static_cast <Card::Suit> (suit); 	   // Casting suit to change datatype int to suit
        for(int r=1;r<14;r++){            	 //looping through all the ranks
            myCards[j] = Card(r,suit2);          //storing card in array
            j++;               			 //incrementing array index
        }
    }
}

void Deck::shuffle()   // shuffle the deck
{
    for(int i=0; i < size(); i++){             //loops through all the remaining cards in the deck
        int card1 = (rand() % size()) + 1;     //getting random for myCard index
        int card2 = (rand() % size()) + 1;     //getting second random for myCard index
        if (card1!=card2){			//if they are not the same random numbers
            int temp = card1;			//set temporary
            myCards[card1]=myCards[card2];	//swap the...
            myCards[card2]=myCards[temp];	//...cards
        }
    }
}

Card Deck::dealCard()   // get a card, after 52 are dealt, fail
{
    Card dealbaby=myCards[myIndex];		//dealbaby hold the exact card with index [myIndex]
    if (size() > 0) {				//when deck is not empty
        myIndex++;				//increment the index to get the next card
        return dealbaby;			//deal the new card 
    }
    else return dealbaby;           		//fixing condition when playing
}

int  Deck::size() const // # cards left in the deck
{
    return (SIZE-myIndex+1);			//Return the number of cards left in the deck 
}
