#include <cstdlib>
#include <vector>
#include <iostream>
#include <ctime>

using namespace std;

class Code{
/*private:
    int n, m;*/
public:
    //void code(n,m)
    int n; //number of digits in vectors
    int m; //range of digits in vectors
    vector<int> Secret; //secret vector
    vector<int> Guess; //guess vector

    Code(int n1, int m1){
        n = n1;
        m = m1;
    }

    void setRandomCode(void); //function to set random values vector
    void setGuess(int gs[]); //function to set guess values vector
    int checkCorrect(void); //function to check correct digits in correct location
    int checkIncorrect(void); //function to check correct digits in incorrect location
    string returnRandom(void);
    string returnGuess(void);
};

void Code::setRandomCode(void){
    while(!Secret.empty()){
        Secret.pop_back();
    }
    srand(time(NULL));
    for(int i = 0; i<n; i++){
        Secret.push_back(rand() % m);
    }
}

void Code::setGuess(int gs[]){
    for(int i = 0; i<n; i++){
        Guess.push_back(gs[i]);
    }
}

int Code::checkCorrect(void){
    int correct = 0;
    bool result;
    for(int i = 0; i<n; i++){
        if(equal(Secret.begin() + i, Secret.begin() + i, Guess.begin() + i)){
            correct++;
        }
    }
    return correct;
}

/*
int Code::checkIncorrect(int n, vector<int> Secret, vector<int> Guess){
    int incorrect;

}*/

string Code::returnRandom(void){
    for (vector<int>::iterator it = Secret.begin(); it != Secret.end(); ++it)
    cout << ' ' << *it;
    cout << '\n';
}

string Code::returnGuess(void){
    for (vector<int>::iterator it = Guess.begin(); it != Guess.end(); ++it)
    cout << ' ' << *it;
    cout << '\n';
}

int main(){

int Guess1[5] = {5, 0, 3, 2, 6};
int numCorrect;

Code Code1(5, 7);
Code1.setGuess(Guess1);
Code1.setRandomCode();
Code1.returnRandom();
Code1.returnGuess();

numCorrect = Code1.checkCorrect();

cout << numCorrect;

//sample guess codes

/*int Guess2 = {2, 1, 2, 2, 2}
int Guess3 = {1, 3, 3, 4, 5}*/

}
