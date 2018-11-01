/*Main Function
Written by Andrew Ricci and Julian Perez*/

#include "deck.h"
#include <iostream>

using namespace std;

void playFlip();

int main(){
    playFlip();
}

void playFlip(){
    //constructs deck and shuffles three times
    Deck deck1;
    deck1.shuffleDeck();
    deck1.shuffleDeck();
    deck1.shuffleDeck();
    //prints out the first 24 cards for test purposes
    deck1.print24();
    //sets variables to track score and user input
    char input;
    double score = 0;

    cout << "Welcome to Flip! 24 cards have been dealt."<<endl;
    cout << "Flip cards until 24 or you wish to stop."<<endl;
    cout << "Press f and enter to flip the next card"<<endl;
    cout << "Enter any other value to end the game"<<endl;

    //takes user input
    cin >> input;

    //game continues while user inputs f
    while(input == 'f'){
        //creates card and sets it as dealed card
        Card card1 = deck1.deal();
        //scores cards as determined by game rules
        if (card1.getValue() == 1){
            score += 10;
        }
        else if(card1.getValue() <= 13 && card1.getValue() >= 11){
            score += 5;
        }
        else if(card1.getValue() <= 10 && card1.getValue() >= 8){
            score += 0;
        }
        else if(card1.getValue() == 7){
            score = score / 2;
        }
        else if(card1.getValue() <= 6 && card1.getValue() >= 2){
            score = 0;
        }

        if(card1.getSuit() == 'H'){
            score += 1;
        }

        //returns card and the user's current score
        cout << "Card flipped: " << card1 << "\n Score: " << score << endl;
        //removes card from top of the deck
        deck1.replace(card1);
        //takes next input to continue or end game
        cin >> input;
    }
    cout <<"\nGame over! Your final score is: " << score << endl;

    deck1.printDeck();
}
