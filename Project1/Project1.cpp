#include <cstdlib>
#include <vector>
#include <iostream>
#include <ctime>

using namespace std;

class Code{

public:
	//void code(n,m)
	int n; //number of digits in vectors
	int m; //range of digits in vectors
	vector<int> Secret; //secret vector
	vector<int> Guess; //guess vector

	Code(int n1, int m1){ //constructor, sets values in main function to n and m
		n = n1;
		m = m1;
	}

	void setRandomCode(void); //function to set random values vector
	void setGuess(int gs[]); //function to set guess values vector
	int checkCorrect(void); //function to check correct digits in correct location
	int checkIncorrect(void); //function to check correct digits in incorrect location
};

void Code::setRandomCode(void){
	while (!Secret.empty()){ //deletes any existing secret values
		Secret.pop_back();
	}
	srand(time(NULL)); //sets random value based on clock
	for (int i = 0; i<n; i++){
		Secret.push_back(rand() % m); //pushes n random values to vector
	}
}

void Code::setGuess(int gs[]){
	for (int i = 0; i<n; i++){ //pushes guess values to guess vector
		Guess.push_back(gs[i]);
	}
}

int Code::checkCorrect(void){
	int correct = 0;
	for (int i = 0; i<n; i++){
		if (Secret[i] == Guess[i]){ //compares secret values to guess values
			correct++; //if matching, adds 1
		}
	}
	return correct;
}


int Code::checkIncorrect(void){
	int incorrect;
}

int main(){

	int Guess1[5] = { 5, 0, 3, 2, 6 };
	int numCorrect;

	Code Code1(5, 7); //initializes code with vector of length 5 and values 0-6
	Code1.setGuess(Guess1); //sets guess to given guess value
	Code1.setRandomCode(); //generates secret code
	vector<int> sekret = Code1.Secret; //sets class vectors to local vectors (delete)
	vector<int> goose = Code1.Guess;

	for (vector<int>::iterator it = sekret.begin(); it != sekret.end(); ++it){ //prints random and guess vectors (delete)
		cout << *it << ' ';
	}
	cout << '\n';
	for (vector<int>::iterator it = goose.begin(); it != goose.end(); ++it){
		cout << *it << ' ';
	}
	cout << '\n';
	numCorrect = Code1.checkCorrect(); //uses check correct function to set number of correct values

	cout << numCorrect; //outputs number of correct values

	//sample guess codes
	/*int Guess2 = {2, 1, 2, 2, 2}
	int Guess3 = {1, 3, 3, 4, 5}*/

}