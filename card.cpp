#include <iostream>
#include "card.h"

using namespace std;


Card::Card(){                                       //Initialize it to the Ac of spades - default constructor
    myRank=1;
    mySuit=spades;}

Card::Card(int rank, Suit s) {                     //Constructor when given an input
//suit is either spades, clubs, hearts, diamonds
    myRank=rank;
    mySuit=s;
}
// The function toString() converts a card to a string, e.g., to print
// return string version e.g. Ac 4h Js
string Card::toString()const{
    string string;                                     //String that will return my result
    switch(mySuit){
        case spades : string= string.append(rankString(getRank()));     //Give me the rank
        string= string.append(suitString(spades));
        break;}
    switch(mySuit){
        case clubs : string = string.append(rankString(getRank()));     //rankString will give me the string of the rank by calling get Rank
        string = string.append(suitString(clubs));                      //Append allowed me to join the rank and the string
        break;
        }
    switch(mySuit){
        case hearts : string = string.append(rankString(getRank()));    //String = rank as a string
        string = string.append(suitString(hearts));                     //String = rank string+the suit string together
        break;}
    switch(mySuit){
        case diamonds : string = string.append(rankString(getRank()));  //String has the rank as string
        string = string.append(rankString(getRank()));
        break;
    }
return string;  //return string as e.g. Ac 4h Js
}

// true if suit same as c
//input is a card
bool Card::sameSuitAs(const Card& c)const{                              //bool expressions already written
     return(mySuit == c.mySuit);}

// return rank, 1..13
int  Card::getRank()const{
    return (myRank);}

// return "s", "h",...
string Card::suitString(Suit s)const{
string string;
    if (s==spades){
        return string = "s";
    }
    else if(s==hearts){
        return string= "h";
    }
    else if(s==clubs){
        return string = "c";
    }
    else if (s==diamonds){
        return string = "d";
    }
}

// return "A", "2", ..."Q"  append
string Card::rankString(int r)const{
    string string;                              //String where the rank is return
    if (r==1){return string="A";}
    else if (r>=2 && r<=10){return string = to_string(r);}
    else if (r==11){return string="J";}
    else if (r==12){return string="Q";}
    else if (r==13){return string="K";}
}