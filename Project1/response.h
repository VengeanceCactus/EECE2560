/*
Response header file. Written by Andrew Ricci and Julian Perez.
*/

#include <cstdlib>
#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

class Response{
    public:
        int cor;
        int incor;

        Response();

        void correctSet(int cor1);
        void incorrectSet(int incor1);
        int correctGet();
        int incorrectGet();
};
