/*
Project 1a main file. Written by Andrew Ricci and Julian Perez.
*/
#include <cstdlib>
#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>
#include "code.h"

using namespace std;

void Code::setRandomCode(void){
	while (!Secret.empty()){ //deletes any existing secret values
		Secret.pop_back();
	}
	srand(time(NULL)); //sets random value based on clock
	for (int i = 0; i < n; i++){
		Secret.push_back(rand() % m); //pushes n random values to vector
	}
}

void Code::setGuess(int gs[]){
	for (int i = 0; i < n; i++){ //pushes guess values to guess vector
		Guess.push_back(gs[i]);
	}
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
	return incorrect;
}

int main(){

	int Guess1[5] = { 5, 0, 3, 2, 6 };
	int numCorrect;
	int numIncorrect;

	Code Code1(5, 7); //initializes code with vector of length 5 and values 0-6
	Code1.setGuess(Guess1); //sets guess to given guess value
	Code1.setRandomCode(); //generates secret code
	vector<int> sekret = Code1.Secret; //sets class vectors to local vectors (display purposes only)
	vector<int> goose = Code1.Guess;

	for (vector<int>::iterator it = sekret.begin(); it != sekret.end(); ++it){ //prints random and guess vectors (display purposes only)
		cout << *it << ' ';
	}
	cout << '\n';
	for (vector<int>::iterator it = goose.begin(); it != goose.end(); ++it){
		cout << *it << ' ';
	}
	cout << '\n';
	numCorrect = Code1.checkCorrect(); //uses check correct function to set number of correct values
	numIncorrect = Code1.checkIncorrect(); //uses check incorrect function to set number of incorrect values

	cout << numCorrect << ", " << numIncorrect; //outputs number of correct values

	//sample guess codes
	/*int Guess2 = {2, 1, 2, 2, 2}
	int Guess3 = {1, 3, 3, 4, 5}*/

}
