#include <cstdlib>
#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>
//#include "response.h"

using namespace std;

class Response{
    public:
        int cor;
        int incor;

        Response(int cor1, int incor1){
            cor = cor1;
            incor = incor1;
        }

        void ResponseSet();
        void ResponseGet();

        Response operator=={
        }
        Response operator<<{
        }
}

void CorrectSet(void){
    cor = cor1;
}

void IncorrectSet(void){
    incor = incor1;
}

void CorrectGet(void){
    return cor;
}

void IncorrectGet(void){
    return incor;
}
