/*Main Function
Written by Andrew Ricci */

#include "deck.h"
#include <iostream>

using namespace std;

int main(){
    Deck deck1;
    cout << "Deck in order:" <<endl;
    deck1.printDeck();
    deck1.shuffleDeck();
    cout <<"\n";
    cout << "Randomly shuffled deck: "<<endl;
    deck1.printDeck();
}
