/*Node Header
Written by Andrew Ricci and Julian Perez*/

#include "card.h"
#include <iostream>

class Node{
public:
    Node(Card card1);
    Node(Card card1, Node *n);

    Node *next;
    Card card;
};
