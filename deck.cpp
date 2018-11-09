#include <iostream>
#include "deck.h"
#include <cstdlib>
#include <ctime>


using namespace std;

Deck::Deck()           // pristine, sorted deck
{   int j=0;		//myCards array index
    myIndex=0;              //initialize my index to move around in Deck
    for(int suit = Card::spades; suit<=Card::clubs; suit++){        //looping through all the suits
        Card::Suit  suit2 = static_cast <Card::Suit> (suit); 	   // Casting suit to change datatype int to suit
        for(int r=1;r<14;r++){            	 //looping through all the ranks
            myCards[j] = Card(r,suit2);          //storing card in array
            j++;               			 //incrementing array index
        }
    }
}

void Deck::shuffle()   // shuffle the remaining deck
{
    srand(time(NULL));                      //seeding the random generator witht he clock of prog.
    for(int i=0; i < size(); i++){             //loops through all the remaining cards in the deck
        Card temp2;
        int temp= SIZE - myIndex -1;             //temp to shuffle the right random
        int card1 = (rand() % temp + myIndex);     //getting random for myCard index
        int card2 = (rand() % temp + myIndex);     //getting second random for myCard index
        if (card1!=card2 && size()>1){			//if they are not the same random numbers
            temp2 = myCards[card1];			//set temporary
            myCards[card1]=myCards[card2];	//swap the...
            myCards[card2]=temp2;	//...cards
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
