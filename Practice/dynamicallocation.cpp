#include <iostream>
#include <time24.h>

int main(){
    time24 *timeList;
    timeList = new time24[10];
    for (int i = 0; i < 10; i++){
        timeList[i].setHour(7);
    }
    for(int i = 0; i < 7; i++){
        std::cout << *(timeList+i);
    }
}
