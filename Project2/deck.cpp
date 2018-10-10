/*Deck Class
Written by Andrew Ricci */

#include "deck.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <random>

using namespace std;

//constructs deck class
Deck::Deck(){
    //creates iterative node variables
    Node *prev = NULL;
    Node *cur;
    //adds suits as letter values
    char suit[] = {'C','D','H','S'};
    //iterates through all suits and card numbers
    for (int i = 3; i >= 0; i--){
        for (int j = 13; j > 0; j--){
            //creates card object and iterates to lower value
            cur = new Node(Card(j, suit[i]));
            cur ->next = prev;
            prev = cur;
        }
    }
    //sets first variable to lowest card value
    first = prev;
}

//gets first card from deck
Node * Deck::getFirst(){
    return first;
}

// prints entire deck in order
void Deck::printDeck(){
    //sets new node to first card
    Node *print = first;
    //iterates through deck
    for (int i = 0; i < 52; i++){
        //points to card object within node
        //and outputs with overloaded operator
        cout << print ->card;
        //sets node to next card
        print = print ->next;
    }
}
//places cards in random order
void Deck::shuffleDeck(){
    //first creates a new vector to store list
    vector<Card> cards;
    //creates new node for iterating
    Node *shf = first;
    //iterates like before but pushes to vector
    for (int i = 0; i <52; i++){
        cards.push_back(shf ->card);
        shf = shf ->next;
    }
    //creates random value using time
    default_random_engine rng(time(NULL));
    //shuffles vector using random time value
    shuffle(cards.begin(), cards.end(), rng);
    //populates new list like in deck constructor
    Node *prev = NULL;
    Node *cur;
    for(size_t i=0; i <cards.size(); i++){
        cur = new Node(cards.at(i));
        cur ->next = prev;
        prev = cur;
    }
    first = prev;

}
