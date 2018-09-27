#include <cstdlib>
#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>
#include "mastermind.h"

using namespace std;

Mastermind::Mastermind(){
    n = 5;
    m = 10;
    Code1.setRandomCode(n,m);
}

Mastermind::Mastermind(int n1, int m1){
    n = n1;
    m = m1;
    Code1.setRandomCode(n,m);
}

void Mastermind::printSecretCode(){
    vector<int> sekret = Code1.Secret;

    for (vector<int>::iterator it = sekret.begin(); it != sekret.end(); ++it){ //prints random and guess vectors (display purposes only)
		cout << *it << ' ';
	}
    cout<<"\n";
}

void Mastermind::humanGuess(){
    const int arr = n;
    int gs[arr];
    cout<<"Please enter guess "<<n<<" digits long with values from 0 - "<<m-1<<":\n";
    for(int i = 0; i<n; i++){
        cin>>gs[i];
    }
    Code1.setGuess(gs);
}

void Mastermind::isSolved(){
    int solved = Code1.checkCorrect();
    if(solved == n){
        complete = true;
    }
    else{
        complete = false;
    }
}

void Mastermind::getResponse(){
    cout<<"(Correct in place, correct out of place) = ("<<Code1.checkCorrect()<<", "<<Code1.checkIncorrect()<<")\n";
}

void Mastermind::playGame(){
    Mastermind::printSecretCode();
    for (int tries = 0; tries < 10; tries++){
        Mastermind::humanGuess();
        Mastermind::getResponse();
        Mastermind::isSolved();
        if(complete == true){
            cout<<"You win!";
            break;
        }

    }
}
