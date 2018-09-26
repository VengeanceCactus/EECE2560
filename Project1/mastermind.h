#include <cstdlib>
#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

class Mastermind{

public:
    Mastermind();
    Mastermind(int n1, int m1);

    void printCode();
    void humanGuess();
    void getResponse();
    void isSolved();
    void playGame();
}
