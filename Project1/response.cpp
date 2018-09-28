/*
Project 1 response file. Written by Andrew Ricci and Julian Perez.
*/

#include <cstdlib>
#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>
#include "response.h"

using namespace std;

Response::Response();

int cor1, cor, incor1, incor;

void CorrectSet(cor1){
	Code1.checkCorrect(*correct);
	correct == cor1;
}
void IncorrectSet(incor1){
	Code1.checkIncorrect(*incorrect);
	incorrect == incor1;
}

int CorrectGet(void){
    return cor1;
}

int IncorrectGet(void){
    return incor1;
}
