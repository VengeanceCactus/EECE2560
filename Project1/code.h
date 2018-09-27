/* Code header file. Written by Andrew Ricci and Julian Perez.
*/
#include <cstdlib>
#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

class Code{

public:
    Code();

	int n; //number of digits in vectors
	int m; //range of digits in vectors
	vector<int> initSecret;
	vector<int> initGuess;
	vector<int> Secret; //secret vector
	vector<int> Guess; //guess vector
	void setRandomCode(int n1, int m1); //function to set random values vector
	void setGuess(int gs[]); //function to set guess values vector
	int checkCorrect(void); //function to check correct digits in correct location
	int checkIncorrect(void); //function to check correct digits in incorrect location
};
