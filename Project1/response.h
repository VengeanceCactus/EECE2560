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

        void CorrectSet(cor1);
        void IncorrectSet(incor1);
        int CorrectGet();
        int IncorrectGet();

        Response operator=={
        }
        Response operator<<{
        }
}
