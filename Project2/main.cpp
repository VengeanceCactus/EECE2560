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
    playFlip();
}

//global function for printing results
void playFlip(){
	
	for (int F = 0; F < 24; F++){ //gives user 24 draws
    	cout << "Press F to flip your next card.";
    	cin >> F;
		deck1.deal();
    	deck1.replace();
        card.getValue();
        card.getSuit();
		
		for (int points = 0; points < 100; points++){
		    if (cv = 1){
		    	points = points + 10;
			}
			
			if (cv = 11 || cv = 12 || cv = 13){
				points = points + 5;
			}
			
			if (cv = 8 || cv = 9 || cv = 10){
				points = points;
			}
			
			if (cv = 7){
				points = 0;
			}
			
			if (cv = 2 || cv = 3 || cv = 4 || cv = 5 || cv = 6){
				points = points / 2;
			}
			
			if (st = H){
				points = points + 1;
			}
		}
        
		cout << "You've earned " << points << "points.";
		
		break;	
    }
}
