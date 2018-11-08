#include <iostream>
#include "card.h"

using namespace std;


Card::Card(){                                       //Initialize it to the Ace of spades - default constructor
    myRank=1;
    mySuit=spades;
}

Card::Card(int rank, Suit s) {                     //Constructor when given an input
//suit is either spades, clubs, hearts, diamonds
    myRank=rank;
    mySuit=s;
}

// The function toString() converts a card to a string, e.g., to print
// return string version e.g. Ac 4h Js
string Card::toString()const{
    string s;                                     //String datatype string that will return my result
    switch(mySuit){
        case spades : s = s.append(rankString(getRank()));     //Give me the rank
            s = s.append(suitString(spades));
            break;}
    switch(mySuit){
        case clubs : s = s.append(rankString(getRank()));     //rankString will give me the string of the rank by calling get Rank
            s = s.append(suitString(clubs));                      //Append allowed me to join the rank and the string
            break;}
    switch(mySuit){
        case hearts : s = s.append(rankString(getRank()));    //String = rank as a string
            s = s.append(suitString(hearts));                     //String = rank string+the suit string together
            break;}
    switch(mySuit){
        case diamonds : s = s.append(rankString(getRank()));  //String has the rank as string
            s =  s.append(suitString(diamonds));                     //String = rank string+the suit string together
            break;}
    return s;  //return string as e.g. Ac 4h Js
}

// true if suit same as c
//input is a card
bool Card::sameSuitAs(const Card& c)const{                              //bool expressions already written
    return(mySuit == c.mySuit);}

// return rank, 1..13
int  Card::getRank()const{
    return (myRank);
}

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
    string s = "";
    char buff[3]; //String where the rank is return
//cout << "rting " << itoa(r,buff,10) << endl;
    if (r==1){return s="A";}
    else if (r>=2 && r<=10){return s = s + itoa(r,buff,10);}
    else if (r==11){return s="J";}
    else if (r==12){return s="Q";}
    else if (r==13){return s="K";}
}

bool Card::operator == (const Card& rhs) const{
    return(myRank==rhs.myRank &&
           mySuit==rhs.mySuit);
}
bool Card::operator != (const Card& rhs) const{
    return(myRank!=rhs.myRank &&
           mySuit!=rhs.mySuit);
}

