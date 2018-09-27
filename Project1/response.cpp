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

void CorrectSet(cor1){
    cor = cor1;
}

void IncorrectSet(incor1){
    incor = incor1;
}

int CorrectGet(void){
    return cor;
}

int IncorrectGet(void){
    return incor;
}
