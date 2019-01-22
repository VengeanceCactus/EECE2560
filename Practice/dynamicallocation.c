#include <ostream>

int main(){
    int arr[7];
    arr[0] = 15;
    arr[1] = 23;
    int *p;
    p = arr;
    std::cout << *p;
}
