// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);
void changeturns(Player &turns, Player &p1, Player p2);
void displayhand(Player &p1, Player &p2);

void changeturns(Player& turns, Player p1, Player p2, Player &opponent){
    if(turns==p1){
        turns=p2;
        opponent=p1;
    }
    else if(turns==p2){
        turns=p1;
        opponent=p2;
    }
}


int main( ) {
    bool change;                    //flag to change turns
    int numCards = 7;               //number of cards for each player
    Player p1("Revelo");          //defining player 1
    Player p2("Licona");              //defining player 2
    Player& turns = p2;                   //defining player with turn
    Player& opponent = p1;                //defining opponent
    Deck d;                         //create a deck of cards
    Card c1, c2;                                    //declaring cards for booking
//    Card display;
//    for(int i=0; i<52; i++){
//        display=d.myCards[i];
//        cout<< display.toString() << " " ;
//    }
//    cout << endl;
    d.shuffle();                    //shuffle the cards in deck
//    for(int i=0; i<52; i++){
//        display=d.myCards[i];
//        cout<< display.toString() << " " ;
//    }
//    cout << endl;
    dealHand(d, p1, numCards);      //deal hand for player 1
    dealHand(d, p2, numCards);      //deal hand for player 2
    displayhand(p1, p2);            //display of players
//first before playing players book all pairs they have in their hands
    while(p1.checkHandForBook(c1, c2)){         //find pair in hands
        p1.bookCards(c1, c2);                   //book cards from player
        cout << p1.getname() << ": Found pair " << c1.toString() << " " << c2.toString() << endl; //Critical question
        p1.removeCardFromHand(c1);      //remove card 1
        p1.removeCardFromHand(c2);      //remove card 2
    }
    while(p2.checkHandForBook(c1, c2)){         //find pair in hands
        p2.bookCards(c1, c2);                   //book cards from player
        cout << p2.getname() << ": Found pair " << c1.toString() << " " << c2.toString() << endl; //Critical question
        p2.removeCardFromHand(c1);      //remove card 1
        p2.removeCardFromHand(c2);      //remove card 2
    }
   // turns=p1;                       //player 1 has the first turn
   // opponent=p2;                    //player 2 is the opponent
    cout << "LETS PLAY!" <<endl;            //DEBUG COMMENT
    while(d.size()!=0 && p1.getHandSize()!=0 && p2.getHandSize()!=0){           //loops until game ove
        displayhand(turns, opponent);       //DEBUGG COMMENT
        if(turns.getHandSize()>0 && opponent.getHandSize()>0) {
            c1 = turns.chooseCardFromHand();    //choosing a card from hand to ask for
            cout << turns.getname() << ": Do you have a " << c1.toString() << "?" << endl;     //ask for a rank
            if (opponent.rankInHand(c1)) {            //if true - card is in the opponents hand
                cout << opponent.getname() << ": Yes I do Sir " << turns.getname() << endl;         //out-puting answer
                c1 = turns.removeCardFromHand(c1);     //remove card from hand's opponent
                c2 = opponent.returnCardsameRank(c1);        //gets card to...
                c2 = opponent.removeCardFromHand(c2);        //...remove card from player
                turns.bookCards(c1, c2);                //add card to player's book
                cout << turns.getname() << " book: " << turns.showBooks() <<endl;       //DEBUG COMMENT
                change = false;                           //turns keeps playing
            } else {
                cout << opponent.getname() << ": Go Fish Sir " << turns.getname() << endl;          //tell him to go fish
                if(d.size()>0) {
                    c1 = d.dealCard();               //deal a card from deck
                    cout << "Card from deck: " << c1.toString() << endl;        //DEBUG COMMENT
                    turns.addCard(c1);              //add card to hand
                    cout << "New hand after adding from deck " <<endl ;        //DEBUG COMMNENT
                    displayhand(p1, p2);            //DEBUG COMMENT
                    if(turns.getHandSize()>1) {
                        if (turns.checkHandForBook(c1, c2)) {     //check for pairs
                            turns.bookCards(c1, c2);                   //book cards from player
                            c1 = turns.removeCardFromHand(c1);             //remove card from hand
                            c2 = turns.removeCardFromHand(c2);
                            cout << turns.getname() << ": Found pair " << c1.toString() << " " << c2.toString() << endl; //Critical question
                            change = false;               //turns keeps playing
                        }
                    } else { change = true; }              //flag to change turns
                } else {change = true;}                     //flag to change turns because deck is empty and not pair found
            }
        }
        else if(turns.getHandSize()==0 && d.size()>0){
            c1=d.dealCard();                    //get a card....
            turns.addCard(c1);                  //...and it to hand
            change=true;                        //flag to change turns since you only have 1 card
        }
        else if(turns.getHandSize()==0 && d.size()==0){
            change = true;
        }
        if (change == true) {
            changeturns(turns, p1, p2, opponent);         //change player turns
        }
    }

    changeturns(turns, p1, p2, opponent);
    cout<< "WINNER OF THE GO FISH GAME IS ..............." << endl; //...print out he won
    if(p1.getBookSize()==p2.getBookSize()){     //if a tie!
        cout << "no one, is a tied :( " << endl;
    }
    if(p1.getBookSize()>p2.getBookSize()){      //if player 1 won ...
        cout<< "SIR " << p1.getname() << endl;
    }
    else {                                      //if player 2 won...
        cout << "SIR " << p2.getname() << endl;
    }
}



void dealHand(Deck &d, Player &p, int numCards)
{
   for (int i=0; i < numCards; i++) {
       Card c = d.dealCard();
       p.addCard(c);
   }
}
   



void displayhand(Player &p1, Player &p2){
    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;
}
