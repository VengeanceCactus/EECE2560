/*Node Header
Written by Andrew Ricci */

#include "card.h"
#include <iostream>

class Node{
public:
    Node(Card card1);

    Node *next;
    Card card;
};
