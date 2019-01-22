#include <vector>
#include <iostream>

using namespace std;

int main(){

    vector<char> vecky = {'d','e','f','c','a'};
    swap(vecky.at(1), vecky.at(0));

    for (vector<char>::iterator it = vecky.begin(); it != vecky.end(); ++it){
		cout << *it << ' ';
	}
    cout<<"\n";
}
