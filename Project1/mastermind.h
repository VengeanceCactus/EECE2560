/*
Mastermind header file. Written by Andrew Ricci and Julian Perez
*/

#include <cstdlib>
#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>
#include "code.h"
//#include "response.h"

using namespace std;

class Mastermind{

public:
    int n;
    int m;
    bool complete;

    Mastermind();
    Mastermind(int n1, int m1);

    Code Code1;
    //Response Res1;

    void printSecretCode();
    void humanGuess();
    void getResponse();
    void isSolved();
    void playGame();
};
