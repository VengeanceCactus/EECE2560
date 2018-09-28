/*
Project 1 Mastermind file. Code by Andrew Ricci and Julian Perez
*/

#include <cstdlib>
#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>
#include "mastermind.h"

using namespace std;

Mastermind::Mastermind(){ //mastermind declared with no parameters
    n = 5; //sets index to 5 and range to 10
    m = 10;
    Code1.setRandomCode(n,m);
}

Mastermind::Mastermind(int n1, int m1){ //mastermind with custom parameters
    n = n1; //sets first value to index and second to range
    m = m1;
    Code1.setRandomCode(n,m);
}

void Mastermind::printSecretCode(){ //prints secret code through iterator for testing
    vector<int> sekret = Code1.Secret;

    for (vector<int>::iterator it = sekret.begin(); it != sekret.end(); ++it){ //prints random and guess vectors (display purposes only)
		cout << *it << ' ';
	}
    cout<<"\n";
}

void Mastermind::humanGuess(){ //takes user input for guess values
    const int arr = n; //sets index value as runtime constant
    int gs[arr]; //creates array of index size
    cout<<"Please enter guess "<<n<<" digits long with values from 0 - "<<m-1<<":\n";
    for(int i = 0; i<n; i++){ //iterates through index value
        cin>>gs[i];
    }
    Code1.setGuess(gs); //sets this array of guesses to Guess vector in Code
}

void Mastermind::isSolved(){ //determines if program was solved
    int solved = Code1.checkCorrect(); //checks number current
    if(solved == n){ //if number equals total, game complete is true
        complete = true;
    }
    else{
        complete = false;
    }
}

void Mastermind::getResponse(){ //displays response using code functions
    cout<<"(Correct in place, correct out of place) = ("<<Code1.checkCorrect()<<", "<<Code1.checkIncorrect()<<")\n";
}

void Mastermind::playGame(){
    Mastermind::printSecretCode(); //begins by printing secret for testing
    for (int tries = 0; tries < 10; tries++){ //gives user 10 tries
        Mastermind::humanGuess();
        Mastermind::getResponse();
        Mastermind::isSolved();
        if(complete == true){ //breaks loop if all numbers match
            cout<<"You win!";
            break;
        }
    }
    if(complete = false){
        cout<<"You lose!";
    }
}
