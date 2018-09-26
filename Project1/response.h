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
