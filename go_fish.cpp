// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"
#include <fstream>

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
    ofstream myfile;
    myfile.open ("text.txt");
    bool change;                    //flag to change turns
    int numCards = 7;               //number of cards for each player
    Player p1("Revelo");          //defining player 1
    Player p2("Licona");              //defining player 2
    Player& turns = p2;                   //defining player with turn
    Player& opponent = p1;                //defining opponent
    Deck d;                         //create a deck of cards
    Card c1, c2;                                    //declaring cards for booking
    d.shuffle();                    //shuffle the cards in deck
    dealHand(d, p1, numCards);      //deal hand for player 1
    dealHand(d, p2, numCards);      //deal hand for player 2
//first before playing players book all pairs they have in their hands
    myfile << "Before playing players must book all pairs they have in hand" << endl;
    while(p1.checkHandForBook(c1, c2)){         //find pair in hands
        p1.bookCards(c1, c2);                   //book cards from player
        myfile << p1.getname() << " says: Found pair " << c1.toString() << " " << c2.toString() << endl; //Critical question
        p1.removeCardFromHand(c1);      //remove card 1
        p1.removeCardFromHand(c2);      //remove card 2
    }
    while(p2.checkHandForBook(c1, c2)){         //find pair in hands
        p2.bookCards(c1, c2);                   //book cards from player
        myfile << p2.getname() << " says: Found pair " << c1.toString() << " " << c2.toString() << endl; //Critical question
        p2.removeCardFromHand(c1);      //remove card 1
        p2.removeCardFromHand(c2);      //remove card 2
    }
    myfile << endl;
    myfile << "LETS PLAY!" <<endl;            //GAME STARTS
    while( (p1.getBookSize()+p2.getBookSize()) !=52 ){           //loops until game ove
        myfile << endl;
        if(turns.getHandSize()>0 && opponent.getHandSize()>0) { //Case where we can ask opponent for cards
            c1 = turns.chooseCardFromHand();    //get a random card form turns hand
            myfile << turns.getname() << " asks: Do you have a " << c1.getRank() << "?" << endl;     //ask for a rank
            if (opponent.rankInHand(c1)) {            //if true - card is in the opponents hand
                myfile << opponent.getname() << " says: Yes I do Sir " << turns.getname() << endl;         //out-puting answer
                c1 = turns.removeCardFromHand(c1);     //remove card from hand's opponent
                c2 = opponent.returnCardsameRank(c1);        //gets card to...
                c2 = opponent.removeCardFromHand(c2);        //...remove card from player
                turns.bookCards(c1, c2);                //add card to player's book
                myfile << turns.getName() << " books " << c1.toString() << " " << c2.toString() << endl;
                change = false;                           //turns keeps playing
            } else {                        //Case were turns fish
                myfile << opponent.getname() << " respond: Go Fish Sir " << turns.getname() << endl;          //tell him to go fish
                if(d.size()>0) {
                    c1 = d.dealCard();               //deal a card from deck
                    myfile << turns.getName() << " draws " << c1.toString() << endl;
                    turns.addCard(c1);              //add card to hand
                    if(turns.getHandSize()>1) {
                        if (turns.checkHandForBook(c1, c2)) {     //check for pairs
                            turns.bookCards(c1, c2);                   //book cards from player
                            c1 = turns.removeCardFromHand(c1);             //remove card from hand
                            c2 = turns.removeCardFromHand(c2);
                            myfile << turns.getname() << " says: Found pair " << c1.toString() << " " << c2.toString() << endl; //Critical question
                            change = false;               //turns keeps playing
                        } else { change = true; }             //flag to change turns pair not found
                    }  else { change = true; }             //flag to change turns only one card (can't compare for pairs)
                } else { change = true; }                     //flag to change turns because deck is empty and not pair found
            }
        }
        else if(d.size()>0){                    //NO CARDS IN ANY OR BOTH PLAYERS
            c1=d.dealCard();                    //get a card....
            myfile << turns.getName() << " draws " << c1.toString() << endl;
            turns.addCard(c1);                  //...and it to hand
            if (turns.checkHandForBook(c1, c2)) {     //check for pairs
                turns.bookCards(c1, c2);                   //book cards from player
                c1 = turns.removeCardFromHand(c1);             //remove card from hand
                c2 = turns.removeCardFromHand(c2);
                myfile << turns.getname() << ": Found pair " << c1.toString() << " " << c2.toString() << endl; //Critical question
                change = false;               //turns keeps playing
            } else { change = true; }             //flag to change turns pair not found
        }
       // else if(turns.getHandSize()==0 && d.size()==0){     //no cards in hands & deck is empty
       //     change = true;
       // }
        if (change == true) {
            changeturns(turns, p1, p2, opponent);         //change player turns
        }
    }
    changeturns(turns, p1, p2, opponent);
    myfile << endl;
    myfile<< "WINNER OF THE GO FISH GAME IS ..............." ; //...print out he won
    if(p1.getBookSize()==p2.getBookSize()){     //if a tie!
        myfile << "no one, is a tied :( " << endl;
    }
    else if(p1.getBookSize()>p2.getBookSize()){      //if player 1 won ...
        myfile<< "SIR " << p1.getname() << endl;
    }
    else if (p1.getBookSize() < p2.getBookSize()){                                      //if player 2 won...
        myfile << "SIR " << p2.getname() << endl;
    }
    myfile << endl;
    myfile << p1.getName() << " booked: " << p1.getBookSize() << " cards" << endl;
    myfile << p2.getName() << " booked: " << p2.getBookSize() << " cards" << endl;
    Deck p;
    myfile.close();

}

void dealHand(Deck &d, Player &p, int numCards)
{
   for (int i=0; i < numCards; i++) {
       Card c = d.dealCard();
       p.addCard(c);
   }
}
