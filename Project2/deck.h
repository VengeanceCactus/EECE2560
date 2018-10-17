/*Deck Header
Written by Andrew Ricci */

#include "node.h"
#include <iostream>

using namespace std;

class Deck{
private:
    Node* first;
public:
    Deck();
    Node* getFirst();

    void printDeck();
    void shuffleDeck();
    void deleteDeck();
    void deal();
    void replace();
};
