#include <iostream>
#include "card.h"

using namespace std;

Card::Card(){}

void Card::setValue(int cv1){
    cv = cv1;
}

void Card::setSuit(char st1){
    st = st1;
}

int Card::getValue(){
    return cv;
}

char Card::getSuit(){
    return st;
}

