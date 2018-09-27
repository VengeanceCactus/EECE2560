/*
Project 1 Code file. Written by Andrew Ricci and Julian Perez.
*/
#include <cstdlib>
#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>
#include "code.h"

using namespace std;

Code::Code(){} //constructor

void Code::setRandomCode(int n1, int m1){
    n = n1;
    m = m1;
	while (!Secret.empty()){ //deletes any existing secret values
		Secret.pop_back();
	}
	srand(time(NULL)); //sets random value based on clock
	for (int i = 0; i < n; i++){
		Secret.push_back(rand() % m); //pushes n random values to vector
	}
	initSecret = Secret; //saves initial unmarked value
}

void Code::setGuess(int gs[]){
    while (!Guess.empty()){ //deletes any existing guess values
		Guess.pop_back();
	}
	for (int i = 0; i < n; i++){ //pushes guess values to guess vector
		Guess.push_back(gs[i]);
	}
	initGuess = Guess; //saves initial unmarked value
}

int Code::checkCorrect(void){
	int correct = 0;
	for (int x = 0; x < n; x++){
		if (Secret[x] == Guess[x]){ //compares secret values directly to guess values
			correct++; //if matching, adds 1
			Guess[x] = 'c'; //marks the guess value as correct so not used again
			Secret[x] = 'C'; //marks the secret value as correct so not used again
		}
	}
	return correct;
}


int Code::checkIncorrect(void){
	int incorrect = 0;
	for (int x = 0; x < n; x++){ //iteration for guess values
		for (int i = 0; i < n; i++){ //iteration for secret values within each guess iteration
			if (Guess[x] == Secret[i]){ //compares the guess iteration with each secret value
				incorrect++; //if a guess value matches with any other secret value, adds 1
				Guess[x] = 'i'; //marks the guess value as incorrect match so not used again
				Secret[i] = 'I'; //marks the secret value as incorrect match so not used again
			}
		}
	}
	Secret = initSecret; //returns secret and guess to initial values before marking
	Guess = initGuess;
	return incorrect;
}
