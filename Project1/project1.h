#include <cstdlib>
#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>

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
