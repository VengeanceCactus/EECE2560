#include <cstdlib>
#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>
#include "mastermind.h"

using namespace std;

Mastermind::Mastermind(){
    n = 5;
    m = 10;
}

Mastermind::Mastermind(int n1, int m1){
    n = n1;
    m = m1;
}
