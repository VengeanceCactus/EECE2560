/*Deck Header
Written by Andrew Ricci and Julian Perez*/

#include "node.h"
#include <iostream>

using namespace std;

class Deck{
private:
    Node* first;
public:
    Deck();
    ~Deck();
    Node* getFirst();
    Node* deleteFirst();

    Card deal();
    void replace(Card card1);
    void printDeck();
    void print24();
    void shuffleDeck();
};
