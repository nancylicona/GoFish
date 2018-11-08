#include <iostream>
#include "player.h"
#include <iterator>
#include <cstdlib>
#include <ctime>

using namespace std;

Player::Player() {
    myName="";          //set to empty string
    myHand.resize(0);   //set to size 0
    myBook.resize(0);   //set to size 0
}

string Player::getname()const{
    return myName;
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
    if(myHand.size() > 1) {
        for (iter = myHand.begin(); iter != (myHand.end() - 1); iter++) {        //loops through all the hand
            card1 = *iter;             //define card1
            for (iter2 = iter + 1; iter2 != myHand.end(); iter2++) {
                card2 = *iter2;           //define card2
                if (card1.getRank() == card2.getRank()) {       //if the ranks are the same
                    c1 = card1;       //store card1
                    c2 = card2;       //store card2
                    return true;      //pair found
                }
            }
        }
    }
    return false;           //pair not found
}

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

//uses some strategy to choose one card from the player's
//hand so they can say "Do you have a 4?"
Card Player::chooseCardFromHand() const{
    //srand(time(NULL));                      //seeding the random generator witht he clock of prog.
    Card Card1;                                         //declaring Card1
    unsigned long temp;                                 //declaring temp to hold random number
    unsigned long handsize;                             //declaring hand size to hold size of cards in hand
    vector<Card>::const_iterator pointer=myHand.begin();    //declaring pointer which points to the beginning of myHands vector
    if(myHand.size()>1) {
        handsize = myHand.size() - 1;                         //getting size of myHand
        srand(time(NULL));
        temp = rand() % handsize;                              //temp holds the random number from 0 to myHand.size - 1
        Card1 = *(pointer + temp);                            //store card in variable...
        return Card1;                                       //return that random card
    }
    else{
        Card1 = myHand[0];
        return Card1;
    }
}


//Does the player have the card c in her hand?
bool Player::cardInHand(Card c) const{
    vector<Card>::const_iterator pointer;                                       //Pointer that goes through the vector array
    for(pointer=myHand.begin(); pointer!=myHand.end(); pointer++){              //loop through hand
        if (c == *pointer){                                                     //De-referencing pointer - Comparing both cards, suit and rank
            return true;}}                                                      //if same then true
    return false;
}                                                              //false otherwise


//Remove the card c from the hand and return it to the caller
Card Player::removeCardFromHand(Card c){
    Card cardremove = c;                                                        //Copy of the card to be removed
    int index;                                                                  //position in hand where card is
    int sizehand=myHand.size();                                                 //Getting the size of my hand with vector function
    for (index=0; index<sizehand; index++){                                     //for loop - increments the index when the card is not found
        if(myHand[index]==c){                                                   //when found then break - index does not increment again
            break;}
    }
    myHand.erase(myHand.begin()+index);                                         //Erase the card with index
    return cardremove;                                                          //return the card that is been erase
}


//Returns a string with the cards in Hands
string Player::showHand() const{
    Card Cardtemp;              //declaring a Card temp that holds one card from hand
    string s;              //string that will be return
    vector<Card>::const_iterator pointer;           //declaring pointer
    for(pointer=myHand.begin(); pointer!=myHand.end(); pointer++){          //loops through the cards in hand
        Cardtemp=*pointer;                      //store card in temp
        s=s.append(Cardtemp.toString());      //switch it to string and attach it to the string
        s=s.append(" ");                      //attack space between cards
    }
    return s;
}

//Returns a string with the cards in Book
string Player::showBooks() const{
    Card Cardtemp;              //declaring a Card temp that holds one card from book
    string s;              //string that will be return
    vector<Card>::const_iterator pointer;           //declaring pointer
    for(pointer=myBook.begin(); pointer!=myBook.end(); pointer++){          //loops through the cards in book
        Cardtemp=*pointer;                      //store card in temp
        s=s.append(Cardtemp.toString());      //switch it to string and attach it to the string
        s=s.append(" ");                      //attack space between cards
    }
    return s;
}

int Player::getHandSize() const{
    return myHand.size();                               //return an int of the number of cards in my hand
}
int Player::getBookSize() const{
    return myBook.size();                               //return an int of the number of cards in my book
}

//Compares the ranks from c and returns the card with the same rank
Card Player::returnCardsameRank (Card c) const{
    Card temp;                              //holds cards from hand
    vector<Card>:: const_iterator pointer;          //pointer to iterate vector
    for(pointer=myHand.begin(); pointer!=myHand.end(); pointer++){      //loops through hand
        temp=*pointer;              //dereferencing the pointer
        if(c.getRank()==temp.getRank()){            //if rank is the same
            return temp;            //return that card
        }
    }
}


bool Player::operator == (const Player& rhs) const{
    return(myName==rhs.myName);
}


