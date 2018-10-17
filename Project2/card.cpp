/*Card Class
Written by Andrew Ricci */

#include <iostream>
#include <sstream>
#include "card.h"

using namespace std;

//creates a card with blank values
Card::Card(){
    cv = 0;
    st = ' ';
}
//creates a card with given card and suit values
Card::Card(int cv1, char st1){
    cv = cv1;
    st = st1;
}
//sets card value
void Card::setValue(int cv1){
    cv = cv1;
}
//sets suit value
void Card::setSuit(char st1){
    st = st1;
}
//returns card value
int Card::getValue(){
    return cv;
}
//returns suit value
char Card::getSuit(){
    return st;
}

//operator overload to print card
ostream& operator<<(ostream& print, Card& Card1){
    stringstream out;
    string a,b;
    //converts chars to full names
    if(Card1.getSuit() == 'H'){
        a = "Hearts";
    }
    else if(Card1.getSuit() == 'S'){
        a = "Spades";
    }
    else if (Card1.getSuit() == 'C'){
        a = "Clubs";
    }
    else if (Card1.getSuit() == 'D'){
        a = "Diamonds";
    }
    else{
        a = "Invalid Suit";
    }
    //converts card values to royal cards and aces
    if(Card1.getValue() > 10 || Card1.getValue() < 2){
        if(Card1.getValue() == 11){
            b = "Jack";
        }
        else if (Card1.getValue() == 12){
            b = "Queen";
        }
        else if (Card1.getValue() == 13){
            b = "King";
        }
        else if (Card1.getValue() == 1){
            b = "Ace";
        }
        else
            b = "Invalid Card Value";
    }
    else{
        out << Card1.getValue();
        b = out.str();
    }
    //outputs full card names
    print << b << " of " << a <<endl;
    return print;
}

//copy constructor and overloaded assignment (INCOMPLETE)
template <typename T>
dynamicClass<int> card1(dynamicClass<T>)
	
