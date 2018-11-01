/* Written by Andrew Ricci */

#include "dictionary.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

Dictionary::Dictionary(){}

void Dictionary::readDict(){
    //loads dictionary
    ifstream file("dictionary.txt");

    string word;
    //for entire file, adds words to vector
    while(file >> word){
        dict.push_back(word);
    }
}

void Dictionary::printDict(){
    //iterates through vector and prints all values
    for (vector<string>::iterator it = dict.begin(); it != dict.end(); ++it){
		cout << *it << ' ';
	}
    cout<<"\n";
}

void Dictionary::selectionSort(){
    //selection sort algorithm (over 8000 times slower than quicksort!)
    int vecsize = dict.size();
    //iterates through entire vector
    for(int j = 0; j < vecsize - 1; j++){
        //sets min value at current iterator
        string min = dict.at(j);
        int temp = j;
        //moves word to where no other words are less
        for(int i = j + 1; i < vecsize; i++){
            if(min > dict.at(i)){
                min = dict.at(i);
                temp = i;
            }
        }
        //swaps these words
        swap(dict.at(j), dict.at(temp));
    }
}

//quicksort algorithm
void Dictionary::quickSort(){
    sort(dict.begin(), dict.end());
}

void Dictionary::heapSort(){
    //initializes a new heap
    Heap <string> heap1;
    //fills heap with dictionary vector
    heap1.initializeMaxHeap(dict);
    //runs entire heap sorting algorithm
    heap1.heapSort();
    //replaces dictionary with now sorted heap
    dict = heap1.getHeap();
}

void Dictionary::findWord(string search1){
    //runs a binary search on entire dictionary for word
    if(binary_search(dict.begin(), dict.end(), search1)){
        cout << search1 <<" was found in dictionary."<<endl;
    }
    else{
        cout << "Could not find " << search1 <<" in dictionary."<<endl;
    }
}


