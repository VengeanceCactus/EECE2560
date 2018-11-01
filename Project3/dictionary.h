/*Written by Andrew Ricci */

#include <vector>
#include <string>
#include "heap.h"

using namespace std;

class Dictionary{
public:
    vector<string> dict;

    Dictionary();
    //reads from dictionary file and saves as vector
    void readDict();
    //overloaded operator that will print list of words
    void printDict();
    //sorts words using quick sort
    void quickSort();
    //sorts words using selection sort
    void selectionSort();
    //sorts words using heap sort
    void heapSort();
    //finds words using binary search
    void findWord(string search1);

};
