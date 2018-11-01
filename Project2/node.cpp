/*Node Class
Written by Andrew Ricci and Julian Perez*/

#include "node.h"

//constructs a list node with card data
Node::Node(Card card1){
    next = NULL;
    card = card1;
}

Node::Node(Card card1, Node *n){
    next = n;
    card = card1;
}
